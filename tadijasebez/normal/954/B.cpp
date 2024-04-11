#include <stdio.h>
const int N=10000;
char s[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int sol,n,i,j;
	scanf("%i",&n);
	scanf("%s",s+1);
	sol=n;
	for(i=1;i<=n/2;i++)
	{
		bool ok=1;
		for(j=1;j<=i;j++)
		{
			if(s[j]!=s[i+j]) ok=0;
		}
		if(ok) sol=min(sol,n-i+1);
	}
	printf("%i\n",sol);
	return 0;
}