#include<stdio.h>
#include<string.h>
char s[1000020];
char c[1000020];
int l,r;
int main()
{
	scanf("%s %s",s,c);
	for(r=0;s[r]==c[r];)
		r++;
	for(l=strlen(c);l>=0&&s[l+1]==c[l];)
		l--;
	printf("%d\n",r>l?r-l:0);
	for(int i=l+1;i<=r;i++)
		printf("%d ",i+1);
	return 0;
}