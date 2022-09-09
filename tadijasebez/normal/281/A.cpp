#include <stdio.h>
#include <cstring>
char word[1050];
int main()
{
	scanf("%s",&word);
	if(word[0]>='a') word[0]-='a'-'A';
	printf("%s",word);
	return 0;
}