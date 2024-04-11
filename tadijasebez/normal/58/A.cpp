#include <stdio.h>
#include <cstring>
char word[105];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	i=0;
	while(i<n && word[i]!='h') i++;
	i++;
	while(i<n && word[i]!='e') i++;
	i++;
	while(i<n && word[i]!='l') i++;
	i++;
	while(i<n && word[i]!='l') i++;
	i++;
	while(i<n && word[i]!='o') i++;
	if(i<n) printf("YES\n");
	else printf("NO\n");
	return 0;
}