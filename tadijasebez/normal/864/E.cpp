#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
const int N=105;
const int M=2050;
struct item
{
	int t,d,p,i;
	inline bool operator < (const item &b) const
	{
		if(d==b.d) return p>b.p;
		return d<b.d;
	}
} items[N];
int dp[N][M];
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c){ return max(a,max(b,c));}
stack<int> sol;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i %i",&items[i].t,&items[i].d,&items[i].p),items[i].i=i;
	sort(items+1,items+n+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<M;j++)
		{
			if(j<items[i].d && j>=items[i].t)
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-items[i].t]+items[i].p,dp[i-1][j]);
			}
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	printf("%i\n",dp[n][M-1]);
	i=n,j=M-1;
	while(i && j)
	{
		if(j<items[i].d && j>=items[i].t && dp[i][j]==dp[i-1][j-items[i].t]+items[i].p)
		{
			sol.push(i);
			j-=items[i].t;
			i--;
		}
		else if(dp[i][j]==dp[i-1][j])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	printf("%i\n",sol.size());
	while(!sol.empty())
	{
		printf("%i ",items[sol.top()].i);
		sol.pop();
	}
	printf("\n");
	return 0;
}