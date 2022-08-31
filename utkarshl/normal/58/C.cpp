#include"stdio.h"
#include"algorithm"
using namespace std;
int main()
{
	int N,n;
	scanf("%d",&N);
	n=N;
	int inp[n],minimum=100000,maximum=0;
	while(n--)
	{
		scanf("%d",&inp[n]);
		inp[n]-=min(n,N-1-n);
		minimum=min(minimum,inp[n]);
		maximum=max(inp[n],maximum);
	}
	int count[1+maximum-minimum];
	for(int x=minimum;x<=maximum;x++)count[x-minimum]=0;
	for(int i=0;i<N;i++)
	{
		if(inp[i]>0)
		count[inp[i]-minimum]++;
	}
	int m=0;
	for(int i=0;i<maximum-minimum+1;i++)
	{
		m=max(m,count[i]);
	}
	printf("%d\n",N-m);
}