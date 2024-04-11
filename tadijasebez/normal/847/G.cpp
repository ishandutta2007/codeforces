#include <stdio.h>
char ch[10];
int cnt[7];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&ch);
		for(j=0;j<7;j++) cnt[j]+=ch[j]-'0';
	}
	int sol=0;
	for(j=0;j<7;j++) sol=max(sol,cnt[j]);
	printf("%i\n",sol);
	return 0;
}