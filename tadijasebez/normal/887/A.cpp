#include <stdio.h>
#include <cstring>
char ch[1000];
int main()
{
	int n,i,j,sum=0;
	scanf("%s",&ch);
	n=strlen(ch);
	j=0;
	while(j<n && ch[j]=='0') j++;
	for(i=j;i<n;i++) if(ch[i]=='0') sum++;
	if(sum>=6) printf("yes\n");
	else printf("no\n");
	return 0;
}