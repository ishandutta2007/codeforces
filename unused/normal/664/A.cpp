#include <stdio.h>
#include <string.h>
char str1[200], str2[200];
int main()
{
	scanf("%s%s", str1, str2);
	if (strcmp(str1, str2) == 0) printf("%s\n", str1);
	else printf("1\n");
}