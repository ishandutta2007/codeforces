#include <stdio.h>
#include <memory.h>
char a['  '],b['  '];
int main(){
	gets(a);gets(b);
	for(int i=0;i<strlen(a);i++)a[i]=a[i]==b[i]?'0':'1';
	puts(a);
}