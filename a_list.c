/* 
 * a_list.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZENAME 5

struct alist{
	char *name;
	struct alist *next;
};

char name[MAXSIZENAME];
int getname();
void printerror(char* str);
void printlist(struct alist *start);
struct alist* addtolist(char* el_list);
void clearlist(struct alist *start);

struct alist* start;
int length;

int main(){
	while((length = getname(name, MAXSIZENAME)) > 0 ){
		if(length != -1){
			printf("%s", name);
			start = addtolist(name);
		}
	}

	printlist(start);
	clearlist(start);

	return 0;
}

void printlist(struct alist *start){
	printf("\nprint list: \n");
	while(start != NULL){
		printf("%s->", start->name);
		start = start->next;
	}
	printf("\n");
}

void printerror(char* str){
	printf("ERR: %s", str);
}

int getname(char* buffer,unsigned int length){
	char *p;
	char c;

	if (buffer == NULL)
		return -1;
	printf("\ninput name:");
	for( p = buffer; p - buffer <= length && c != EOF && c != '\n'; c = getchar(), *p++ = c );

	*--p=0;
	return p - buffer;
}

struct alist* addtolist(char* el_list){
	struct alist* listik = NULL;
	listik = malloc(sizeof(struct alist));
	if(listik != NULL){
		listik->name = (char*)malloc(strlen(el_list) + 1);
		if(listik->name != NULL){
			strcpy(listik->name, el_list);
			listik->next = start;
			start = listik;
		}else{
			printerror("insufficient memory!");
		}
	}else{
		printerror("insufficient memory!");
	}
	return start;
}

void clearlist(struct alist *start){
	struct alist *tmp;
	while(start != NULL){
		tmp=start->next;
		free(start->name);
		free(start);
		start = tmp;
	}
}

