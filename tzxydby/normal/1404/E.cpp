#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=1000005,INF=1e9;
	int n,s,t;
	struct edge
	{
		int v,w,f,nxt;
	}e[N];
	int head[N],cur[N],cnt;
	void addedge(int u,int v,int w,int f)
	{
		cnt++;
		e[cnt].v=v,e[cnt].w=w,e[cnt].f=f;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		addedge(u,v,w,w);
		addedge(v,u,w,0);
	}
	int dep[N],q[N];
	int bfs()
	{
		for(int i=1;i<=n;i++)
			dep[i]=-1,cur[i]=head[i];
		dep[s]=0;
		int l=0,r=1;
		q[0]=s;
		while(l<r)
		{
			int u=q[l++];
			for(int i=head[u];i;i=e[i].nxt)
			{
				if(dep[e[i].v]==-1&&e[i].f>0)
				{
					dep[e[i].v]=dep[u]+1;
					q[r++]=e[i].v;
				}
			}
		}
		return dep[t]!=-1;
	}
	int dfs(int u,int lim)
	{
		if(u==t||lim==0)
			return lim;
		int flow=0,f;
		for(int i=cur[u];i;i=e[i].nxt)
		{
			cur[u]=i;
			if(dep[e[i].v]==dep[u]+1&&(f=dfs(e[i].v,min(lim,e[i].f))))
			{
				flow+=f;
				lim-=f;
				e[i].f-=f;
				e[(i-1^1)+1].f+=f;
				if(!lim)
					break;
			}
		}
		return flow;
	}
	int max_flow()
	{
		int mf=0;
		while(bfs())
			mf+=dfs(s,INF);
		return mf;
	}
}g;
const int N=205;
int n,m,id[N][N][4],ans,b[N*N*2];
char a[N][N];
vector<int>v;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	g.n=n*m*2+2,g.s=n*m*2+1,g.t=n*m*2+2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
				continue;
			ans++;
			if(a[i-1][j]=='#') id[i][j][0]=(i-2)*m+j;
			if(a[i][j-1]=='#') id[i][j][1]=(i-1)*m+j-1+n*m;
			if(a[i+1][j]=='#') id[i][j][2]=(i-1)*m+j;
			if(a[i][j+1]=='#') id[i][j][3]=(i-1)*m+j+n*m;
			for(int k=0;k<4;k++)
			{
				if(id[i][j][k])
				{
					if(b[id[i][j][k]])
						continue;
					if(k%2==0)
						g.add(g.s,id[i][j][k],1);
					else
						g.add(id[i][j][k],g.t,1);
					b[id[i][j][k]]=1;
					ans--;
				}
			}
			if(id[i][j][0])
			{
				if(id[i][j][1])
					g.add(id[i][j][0],id[i][j][1],1);
				if(id[i][j][3])
					g.add(id[i][j][0],id[i][j][3],1);
			}
			if(id[i][j][2])
			{
				if(id[i][j][1])
					g.add(id[i][j][2],id[i][j][1],1);
				if(id[i][j][3])
					g.add(id[i][j][2],id[i][j][3],1);
			}
		}
	}
	ans=ans+g.max_flow();
	printf("%d\n",ans);
	return 0;
}