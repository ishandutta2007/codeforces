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

int M[200002], S[200002], Su[200002], dp[200002];
int n, k, T[200002], x, res;
vector<int> V[200002];
PII A[2][200002];

void DFS(int v, int prev)
{
	S[v]=1;
	M[v]=T[v];
	if(T[v]<x)
		dp[v]=-1000000000;
	else
		dp[v]=1;
	A[0][v]=MP(0, 0);
	A[1][v]=MP(0, 0);
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(V[v][i]!=prev)
		{
			DFS(V[v][i], v);
			S[v]+=S[V[v][i]];
			M[v]=min(M[v], M[V[v][i]]);
			if(M[V[v][i]]>=x)
				dp[v]+=S[V[v][i]];
			else
			{
				if(dp[V[v][i]]>=A[0][v].F)
				{
					A[1][v]=A[0][v];
					A[0][v]=MP(dp[V[v][i]], i);
				}
				else if(dp[V[v][i]]>=A[1][v].F)
					A[1][v]=MP(dp[V[v][i]], i);
			}
		}
	}
	dp[v]+=A[0][v].F;
	Su[v]=n-S[v];
}

void DFS2(int v, int prev, int mini, int r)
{
	PII mi1=MP(min(mini, T[v]), -1), mi2=MP(1000001, -2);
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(V[v][i]!=prev)
		{
			if(M[V[v][i]]<=mi1.F)
			{
				mi2=mi1;
				mi1=MP(M[V[v][i]], i);
			}
			else if(M[V[v][i]]<=mi2.F)
				mi2=MP(M[V[v][i]], i);
		}
	}
	int re=dp[v]-A[0][v].F;
	if(mini>=x)
		re+=r;
	else
	{
		if(A[0][v].F<=r)
		{
			A[1][v]=A[0][v];
			A[0][v]=MP(r, -1);
		}
		else if(A[1][v].F<=r)
			A[1][v]=MP(r, -1);
	}
	res=max(res, re+A[0][v].F);
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(V[v][i]!=prev)
		{
			int mii=mi1.F;
			if(i==mi1.S)
				mii=mi2.F;
			if(M[V[v][i]]>=x)
				DFS2(V[v][i], v, min(mii, T[v]), re-S[V[v][i]]+A[0][v].F);
			else
			{
				if(A[0][v].S==i)
					DFS2(V[v][i], v, min(mii, T[v]), re+A[1][v].F);
				else
					DFS2(V[v][i], v, min(mii, T[v]), re+A[0][v].F);
			}
		}
	}
}

bool check()
{
	res=0;
	DFS(1, 0);
	DFS2(1, 0, 1000000, 0);
	return res>=k;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	int st=1, en=1000000, mid=(st+en)/2, r=0;
	while(st<=en)
	{
		//printf("%d\n", mid);
		x=mid;
		if(check())
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	printf("%d\n", r);
	return 0;
}