#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

LL n, T[100005];
LL dp[100005][4];
vector<int> V[100005];

void DFS(int v, int prev)
{
	PLL a[4][3];
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(V[v][i]==prev)
			continue;
		int u=V[v][i];
		DFS(u, v);
		for(int k=0; k<4; k++)
		{
			if(dp[u][k]>=a[k][0].F)
			{
				a[k][2]=a[k][1];
				a[k][1]=a[k][0];
				a[k][0]=MP(dp[u][k], u);
			}
			else
			{
				if(dp[u][k]>=a[k][1].F)
				{
					a[k][2]=a[k][1];
					a[k][1]=MP(dp[u][k], u);
				}
				else
					if(dp[u][k]>=a[k][2].F)
						a[k][2]=MP(dp[u][k], u);
			}
		}
	}
	dp[v][1]=a[1][0].F+T[v];
	dp[v][0]=max(max(dp[v][1], a[0][0].F), a[1][0].F+a[1][1].F+T[v]);
	dp[v][2]=max(max(dp[v][0], a[2][0].F+T[v]), dp[v][1]);
	for(int k=0; k<2; k++)
	{
		LL x=a[1][k].F+T[v];
		if(a[1][k].S!=a[0][0].S)
			x+=a[0][0].F;
		else
			x+=a[0][1].F;
		dp[v][2]=max(dp[v][2], x);
	}
	dp[v][3]=max(max(dp[v][2], a[3][0].F), a[0][0].F+a[0][1].F);
	for(int k=0; k<3; k++)
	{
		LL x=a[0][k].F+T[v];
		if(a[1][0].S==a[0][k].S)
			x+=a[1][1].F+a[1][2].F;
		else
		{
			if(a[1][1].S==a[0][k].S)
				x+=a[1][0].F+a[1][2].F;
			else
				x+=a[1][0].F+a[1][1].F;
		}
		dp[v][3]=max(dp[v][3], x);
	}
	for(int k=0; k<2; k++)
	{
		LL x=a[2][k].F+T[v];
		if(a[1][0].S==a[2][k].S)
			x+=a[1][1].F;
		else
			x+=a[1][0].F;
		dp[v][3]=max(dp[v][3], x);
	}
}


int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld", &n);
	for(int i=1; i<=n; i++)
		scanf("%lld", T+i);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	DFS(1, 0);
	printf("%lld\n", dp[1][3]);
	return 0;
}