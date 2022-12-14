#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<long long,int> P;//for dijkstra

const long long inf=1ll<<60;

struct edge{
	int to,cost;
	edge(){}
	edge(int a,int b):to(a),cost(b){}
};

vector<edge> G[1010];

long long dis[1010][1010];//[i][j]=i->j min dis

int cango[1010],cost[1010];

long long ans[1010];

int main()
{
	int N,M,x,y;
	scanf("%d%d",&N,&M);
	scanf("%d%d",&x,&y);
	x--;y--;
	for(int i=0;i<M;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u--;v--;
		G[u].push_back(edge(v,c));
		G[v].push_back(edge(u,c));
	}
	for(int i=0;i<1010;i++) for(int j=0;j<1010;j++) dis[i][j]=inf;
	for(int s=0;s<N;s++)
	{
		priority_queue<P,vector<P>,greater<P> > que;
		que.push(P(0,s));
		dis[s][s]=0;
		while(!que.empty())
		{
			P p=que.top();
			que.pop();
			long long t=p.first;
			int v=p.second;
			if(dis[s][v]<t)
			{
				continue;
			}
			for(int i=0;i<G[v].size();i++)
			{
				int nv=G[v][i].to;
				long long nt=t+G[v][i].cost;
				if(dis[s][nv]<=nt) continue;
				dis[s][nv]=nt;
				que.push(P(nt,nv));
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",cango+i,cost+i);
		ans[i]=inf;
	}
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,x));
	ans[x]=0;
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;
		long long c=p.first;
		if(ans[v]<c) continue;
		for(int i=0;i<N;i++)
		{
			int nv=i;
			long long nc=c+cost[v];
			if(cango[v]<dis[v][nv]) continue;
			if(ans[nv]<=nc) continue;
			ans[nv]=nc;
			que.push(P(nc,nv));
		}
	}
	if(ans[y]==inf) printf("-1\n");
	else cout<<ans[y]<<"\n";
	return 0;
}