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
#define int LL
const LL inf=1e18+2;

struct edge
{
	int a, b, w;
};

int n, m, x;
vector<edge> X;
int flow[55][55], dist[55], q[55];
vector<int>::iterator start[55];
vector<int> V[55];


int bfs()
{
	for(int i=1; i<=n; i++)
		dist[i]=-1;
	dist[1]=0;
	int st=0, en=0;
	q[en++]=1;
	while(st<en)
	{
		int v=q[st++];
		for(vector<int>::iterator it=V[v].begin(); it!=V[v].end(); ++it)
		{
			if(flow[v][*it]>0 && dist[*it]==-1)
			{
				dist[*it]=dist[v]+1;
				q[en++]=*it;
			}
		}
	}
	return dist[n]!=-1;
}

int dfs(int x, int mini)
{
	int res=0;
	if(x==n || mini==0)
		return mini;
	for(vector<int>::iterator &it=start[x]; it!=V[x].end(); ++it)
	{
		if(dist[x]+1==dist[*it] && flow[x][*it]>0)
		{
			int y=dfs(*it, min(mini, flow[x][*it]));
			flow[x][*it]-=y;
			flow[*it][x]+=y;
			mini-=y;
			res+=y;
			if(mini==0)
				break;
		}
	}
	return res;
}

int maxflow()
{
	int res=0;
	while(bfs())
	{
		for(int i=1; i<=n; i++)
			start[i]=V[i].begin();
		res+=dfs(1, inf);
	}
	return res;
}

main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld%lld%lld", &n, &m, &x);
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		edge x;
		x.a=a;
		x.b=b;
		x.w=c;
		X.PB(x);
		V[a].PB(b);
		V[b].PB(a);
	}
	double st=0.0, en=1000000.0, mid=(st+en)/2, res=0.0;
	for(int qwe=0; qwe<60; qwe++)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				flow[i][j]=0;
		for(int i=0; i<m; i++)
			flow[X[i].a][X[i].b]+=(int)((double)X[i].w/mid);
		if(maxflow()>=x)
		{
			res=max(res, mid*(double)x);
			st=mid;
		}
		else
			en=mid;
		mid=(st+en)/2;
	}
	printf("%.8lf\n", res);
	return 0;
}