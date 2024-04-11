#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1<<29;

int dis[110];

long long come[110],go[110];

vector<int> G[110];

queue<int> que;

long long get_come(int v)
{
	if(come[v]!=-1) return come[v];
	long long res=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(dis[G[v][i]]==dis[v]-1) res+=get_come(G[v][i]);
	}
	come[v]=res;
	return res;
}

long long get_go(int v)
{
	if(go[v]!=-1) return go[v];
	long long res=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(dis[G[v][i]]==dis[v]+1) res+=get_go(G[v][i]);
	}
	go[v]=res;
	return res;
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++) dis[i]=inf;
	dis[0]=0;
	que.push(0);
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		int d=dis[v];
		for(int i=0;i<G[v].size();i++)
		{
			int nd=d+1;
			int nv=G[v][i];
			if(dis[nv]<=nd) continue;
			que.push(nv);
			dis[nv]=nd;
		}
	}
	memset(come,-1,sizeof(come));
	memset(go,-1,sizeof(go));
	come[0]=1;
	go[N-1]=1;
	double res=1;
	long long all=get_come(N-1);
	for(int i=1;i<N-1;i++)
	{
		long long num=get_come(i)*get_go(i)*2;
		res=max(res,(double)num/all);
	}
	printf("%.9f\n",res);
	return 0;
}