#include<stdio.h>
int p;
char s[100020];
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
		if(s[i]=='0')
		{
			p=i;
			break;
		}
	for(int i=0;s[i];i++)
		if(i!=p)
			printf("%c",s[i]);
}