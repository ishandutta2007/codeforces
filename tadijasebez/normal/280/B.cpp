#include <stdio.h>
const int N=100050;
int S[N],c;
int sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		while(c && x>S[c-1])
		{
			sol=max(sol,x^S[c-1]);
			c--;
		}
		if(c) sol=max(sol,x^S[c-1]);
		S[c]=x;
		c++;
	}
	printf("%i\n",sol);
	return 0;
}