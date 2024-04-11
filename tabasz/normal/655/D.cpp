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

int n, m, res=1000000000, in[100005];
vector<int> V[100005];
vector<PII> E;
queue<int> Q;

bool solve()
{
	vector<int> X;
	for(int i=1; i<=n; i++)
		if(in[i]==0)
			Q.push(i);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		X.PB(v);
		for(int i=0; i<(int)V[v].size(); i++)
		{
			int u=V[v][i];
			in[u]--;
			if(in[u]==0)
				Q.push(u);
		}
	}
	for(int i=0; i<n-1; i++)
	{
		int v=X[i+1];
		bool boo=0;
		for(int j=0; j<(int)V[X[i]].size(); j++)
			if(V[X[i]][j]==v)
				boo=1;
		if(!boo)
			return false;
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		E.PB(MP(a, b));
	}
	int st=0, en=m, mid=(st+en)/2;
	while(st<=en)
	{
		for(int i=0; i<=n; i++)
		{
			V[i].clear();
			in[i]=0;
		}
		for(int i=0; i<mid; i++)
		{
			V[E[i].F].PB(E[i].S);
			in[E[i].S]++;
		}
		if(solve())
		{
			res=min(res, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	if(res==1000000000)
		printf("-1\n");
	else
		printf("%d\n", res);
	return 0;
}