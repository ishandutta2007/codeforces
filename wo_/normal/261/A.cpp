#include<cstdio>
#include<algorithm>

using namespace std;

int prices[100100];

int main()
{
	int M;
	int Q=1000000;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int in;
		scanf("%d",&in);
		Q=min(Q,in);
	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",prices+i);
	sort(prices,prices+N);
	reverse(prices,prices+N);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int rem=i%(Q+2);
		if(rem>=Q) continue;
		ans+=prices[i];
	}
	printf("%d\n",ans);
	return 0;
}