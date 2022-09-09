#include <stdio.h>

int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}

int main()
{
	int n,m,i,lo=0;
	scanf("%i %i",&n,&m);
	int tmp=m;
	while(tmp>0) tmp>>=1,lo++;
	if(lo<n) printf("%i\n",m);
	else
	{
		int mod=1<<n;
		//printf("%i\n",mod);
		m%=mod;
		printf("%i\n",m);
	}
	return 0;
}