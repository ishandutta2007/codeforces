#include <stdio.h>
char baloons[200];
int loons[1000];
int max(int a, int b) {return a>b?a:b;}
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	int sol=0;
	scanf("%s",&baloons);
	for(i=0;i<n;i++)
	{
		loons[baloons[i]]++;
		sol=max(sol,loons[baloons[i]]);
	}
	if(sol<=k) printf("YES\n");
	else printf("NO\n");
	return 0;
}