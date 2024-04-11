#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int head[100100],to[200200],nxt[200200],m=0;
void add_edge(int u,int v)
{
	nxt[m]=head[u];to[m]=v;head[u]=m;m++;
	nxt[m]=head[v];to[m]=u;head[v]=m;m++;
}

int par[100100][18];
int dep[100100];

int lca(int u,int v)
{
	if(dep[u]>dep[v]) swap(u,v);
	int d=dep[v]-dep[u];
	for(int i=0;i<18;i++) if(((d>>i)&1)==1) v=par[v][i];
	if(u==v) return v;
	for(int i=17;i>=0;i--)
	{
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

void dfs(int v,int p,int c)
{
	par[v][0]=p;
	dep[v]=c;
	for(int e=head[v];e!=-1;e=nxt[e])
	{
		int u=to[e];
		if(u==p) continue;
		dfs(u,v,c+1);
	}
}

int getDis(int u,int v)
{
	int p=lca(u,v);
	return dep[u]+dep[v]-dep[p]*2;
}

bool color[100100];
int dis[100100];
int N,M;


vector<int> vec;
int solve(int v)
{
	int ans=dis[v];
	for(int i=0;i<vec.size();i++)
	{
		int u=vec[i];
		ans=min(ans,getDis(u,v));
	}
	return ans;
}

void change(int v)
{
	vec.push_back(v);
	color[v]=true;
}

queue<int> que;
void recalc()
{
	vec.clear();
	for(int i=0;i<N;i++)
	{
		if(color[i])
		{
			dis[i]=0;
			que.push(i);
		}
		else dis[i]=1<<29;
	}
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		for(int e=head[v];e!=-1;e=nxt[e])
		{
			int u=to[e];
			if(dis[u]<=dis[v]+1) continue;
			dis[u]=dis[v]+1;
			que.push(u);
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<100100;i++) color[i]=false;
	color[0]=true;
	for(int i=0;i<100100;i++) head[i]=-1;
	int B=sqrt(M);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		add_edge(u,v);
	}
	dfs(0,-1,0);
	for(int i=1;i<18;i++)
	{
		for(int v=0;v<N;v++)
		{
			if(par[v][i-1]==-1) par[v][i]=-1;
			else par[v][i]=par[par[v][i-1]][i-1];
		}
	}
	for(int i=0;i<M;i++)
	{
		if(i%B==0) recalc();
		int type,v;
		scanf("%d%d",&type,&v);
		v--;
		if(type==1)
		{
			change(v);
		}
		else
		{
			printf("%d\n",solve(v));
		}
	}
	return 0;
}