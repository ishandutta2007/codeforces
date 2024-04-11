#include <stdio.h>
const int N=1000050;
bool sieve[N];
void FindPrimes()
{
	int i,j;
	for(i=2;i<N;i++)
	{
		if(!sieve[i])
		{
			for(j=i*2;j<N;j+=i) sieve[j]=1;
		}
	}
}
int main()
{
	FindPrimes();
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=1000;i++)
	{
		if(sieve[n*i+1]) return printf("%i\n",i),0;
	}
	return 0;
}