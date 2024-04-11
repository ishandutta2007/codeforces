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

vector<int> V[200005];
int n, x, y, in[200005], dp[2][200005];

void DFS(int v, int prev)
{
	for(int i=0; i<(int)V[v].size(); i++)
		if(V[v][i]!=prev)
			DFS(V[v][i], v);
	if((int)V[v].size()>1 || prev==-1)
		dp[0][v]=1;
	int a1=-1000000, a2=-1000000, sum=0;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(V[v][i]!=prev)
		{
			sum+=dp[1][V[v][i]];
			if(dp[0][V[v][i]]-dp[1][V[v][i]]>a1)
			{
				a2=a1;
				a1=dp[0][V[v][i]]-dp[1][V[v][i]];
			}
			else
				if(dp[0][V[v][i]]-dp[1][V[v][i]]>a2)
					a2=dp[0][V[v][i]]-dp[1][V[v][i]];
		}
	}
	dp[0][v]+=sum+a1;
	dp[0][v]=max(dp[0][v], sum);
	dp[1][v]=max(dp[0][v], sum+a1+a2+2);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &x, &y);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		in[a]++;
		in[b]++;
		V[a].PB(b);
		V[b].PB(a);
	}
	int maxin=0;
	for(int i=1; i<=n; i++)
		maxin=max(maxin, in[i]);
	if(x>y)
	{
		if(maxin<n-1)
			printf("%lld\n", (LL)y*(LL)(n-1));
		else
			printf("%lld\n", (LL)y*(LL)(n-2)+(LL)x);
		return 0;
	}
	DFS(1, -1);
	//for(int i=1; i<=n; i++)
	//	printf("%d\n", dp[i]);
	printf("%lld\n", (LL)dp[1][1]*(LL)x+(LL)(n-1-dp[1][1])*(LL)y);
	return 0;
}