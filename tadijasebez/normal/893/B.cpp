#include <stdio.h>
int max(int a, int b){ return a>b?a:b;}
bool Check(int x)
{
	int i,j;
	i=0;
	while(i<20 && !((x>>i)&1)) i++;
	j=i;
	while(j<20 && (x>>j)&1) j++;
	int k;
	for(k=j;k<20;k++) if((x>>k)&1) return 0;
	if(i==(j-i)-1) return 1;
	return 0;
}
int sol=1;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(Check(i)) sol=max(sol,i);
			if(Check(n/i)) sol=max(sol,n/i);
		}
	}
	printf("%i\n",sol);
	return 0;
}