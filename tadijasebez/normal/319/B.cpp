#include <stdio.h>
const int N=100050;
int S[N],C[N],c,naj,sol;
int max(int a, int b){ return a>b?a:b;}
void Insert(int x)
{
	int p=0;
	while(c>0 && S[c-1]<x) c--,p=max(p,C[c]);
	S[c]=x;
	C[c]=p+1;
	sol=max(sol,C[c]);
	c++;
}
int main()
{
	int i,n,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x>naj) naj=x,c=0;
		else Insert(x);
	}
	printf("%i\n",sol);
	return 0;
}