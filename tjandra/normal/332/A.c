#include<stdio.h>
#include<string.h>
typedef unsigned u;
char s[2000];
int main()
{
	u n,l,i,r=0;
	scanf("%u",&n);
	scanf("%s",s);
	l=strlen(s);
	for(i=n;i<l;i+=n)if(s[i-1]==s[i-2]&&s[i-2]==s[i-3])r++;
	printf("%u\n",r);
	return 0;
}