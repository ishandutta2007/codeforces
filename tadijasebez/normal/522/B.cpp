#include <stdio.h>
#include <queue>
using namespace std;
const int N=200050;
pair<int,int> Best;
int sum,h[N],w[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&w[i],&h[i]);
		sum+=w[i];
		if(h[i]>=Best.first)
		{
			Best.second=Best.first;
			Best.first=h[i];
		}
		else if(h[i]>Best.second) Best.second=h[i];
	}
	for(i=1;i<=n;i++)
	{
		int sol=sum-w[i];
		if(h[i]==Best.first) sol*=Best.second;
		else sol*=Best.first;
		printf("%i ",sol);
	}
	printf("\n");
	return 0;
}