#include"stdio.h"
#include"algorithm"
using namespace std;
#define s(x) scanf("%d",&x)
#define INF 1e18
struct s
{
	int pos,cost;
	bool operator<(const s a)const{		return pos<a.pos;	}
};
int main()
{
	int n;
	s(n);
	s x[n];
	for(int i=0;i<n;i++)s(x[i].pos),s(x[i].cost);
	sort(x,x+n);
	long long dp[n];
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=INF;
		long long cost=x[i].cost;
		for(int j=i+1;j<n;j++)
			dp[i]=min(dp[i],cost+dp[j]),
			cost+=x[j].pos-x[i].pos;
		dp[i]=min(dp[i],cost);
	}
	printf("%Ld",dp[0]);
}