#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, tmp;
int in[100005], dp[100005];
bool B[100005], vis[100005];
vector<int> V[100005];

void DFS(int v)
{
	vis[v]=1;
	if(B[v])
		dp[v]++;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i]])
		{
			DFS(V[v][i]);
			dp[v]+=dp[V[v][i]];
		}
	}
}

bool DFS2(int v, int prev)
{
	vis[v]=1;
	int sum=B[v], asd=0;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i]])
		{
			if(dp[V[v][i]]>1 || (dp[V[v][i]]==1 && (int)V[V[v][i]].size()!=3))
				asd++;
			sum+=dp[V[v][i]];
		}
	}
	if(sum+1<tmp || (sum+1==tmp && (int)V[prev].size()!=3))
		asd++;
	if(asd>2)
		return false;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i]] && !DFS2(V[v][i], v))
			return false;
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		in[a]++;
		in[b]++;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i=1; i<=n; i++)
	{
		if(in[i]>2)
		{
			B[i]=1;
			tmp++;
		}
	}
	DFS(1);
	for(int i=1; i<=n; i++)
		vis[i]=0;
	if(DFS2(1, 0))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}