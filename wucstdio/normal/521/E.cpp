#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum=1,head[200005],dfn[200005],low[200005],in[200005];
int st[200005],top,scc;
vector<int>SCC[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void Tarjan(int node,int pre)
{
	if(dfn[node])return;
	dfn[node]=low[node]=++ind;
//	printf("Tarjan(%d):",node);
//	for(int i=1;i<=top;i++)printf("%d ",st[i]);
//	printf("\n");
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(!dfn[to])
		{
			st[++top]=hd>>1;
//			printf("(%d,%d,%d)\n",node,to,hd);
			Tarjan(to,node);
			low[node]=min(low[node],low[to]);
			if(low[to]>=dfn[node])
			{
				int v=st[top--];
				in[v]=++scc;
				SCC[scc].push_back(v);
				while(v!=(hd>>1))
				{
					v=st[top--];
					in[v]=scc;
					SCC[scc].push_back(v);
				}
			}
		}
		else if(to!=pre)
		{
			low[node]=min(low[node],dfn[to]);
			if(dfn[to]<dfn[node])
			{
//				printf("[%d,%d,%d]\n",node,to,hd);
				st[++top]=hd>>1;
			}
		}
	}
}
struct Graph
{
	struct Edge
	{
		int to;
		int nxt;
	}E[400005];
	#define e E
	int uu,n,m,edgenum,head[200005],d[200005],en;
	int p[200005],a[200005],len;
	bool flag[200005],used[200005];
	void add(int u,int v)
	{
		e[++edgenum].to=v;
		e[edgenum].nxt=head[u];
		head[u]=edgenum;
	}
	bool dfs_pre(int node,int pre,int step)
	{
		p[step]=node;
		flag[node]=1;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(pre!=uu&&to==uu)
			{
				len=step;
				return 1;
			}
			if(!flag[to])
			{
				if(dfs_pre(to,node,step+1))
				  return 1;
			}
		}
		flag[node]=0;
		return 0;
	}
	bool dfs(int node,int pre,int step)
	{
		a[step]=node;
		used[node]=1;
		if(flag[node])
		{
			en=node;
			printf("%d ",step);
			for(int i=1;i<=step;i++)printf("%d ",a[i]);
			printf("\n");
			return 1;
		}
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(to==pre||used[to])continue;
			if(dfs(to,node,step+1))return 1;
		}
		used[node]=0;
		return 0;
	}
	void solve(int t)
	{
//		printf("solve(%d):",t);
		int num=(int)SCC[t].size();
		bool ff=0;
		len=en=n=0;
		for(int i=0;i<num;i++)
		{
			#undef e
			int u=e[SCC[t][i]<<1].to;
			int v=e[SCC[t][i]<<1|1].to;
//			printf("(%d,%d) ",u,v);
			#define e E
			if(!d[u])n++;
			if(!d[v])n++;
			d[u]++,d[v]++;
			add(u,v);
			add(v,u);
			if(d[u]>2||d[v]>2)ff=1;
			uu=u;
		}
//		printf("\n");
		if(!ff)
		{
			for(int i=0;i<num;i++)
			{
				#undef e
				int u=e[SCC[t][i]<<1].to;
				int v=e[SCC[t][i]<<1|1].to;
				#define e E
				d[u]=d[v]=head[u]=head[v]=flag[u]=flag[v]=used[u]=used[v]=0;
			}
			return;
		}
		printf("YES\n");
		p[1]=uu;
		dfs_pre(uu,-1,1);
//		printf("p:");
//		for(int i=1;i<=len;i++)printf("%d ",p[i]);
//		printf("\n");
		for(int i=1;i<=len;i++)
		{
			if(d[p[i]]>=3)
			{
				int to=0;
				for(int hd=head[p[i]];hd;hd=e[hd].nxt)
				{
					to=e[hd].to;
					if(to!=p[(i-2+len)%len+1]&&to!=p[i%len+1])break;
				}
//				printf("choose (%d,%d)\n",p[i],to);
				a[1]=p[i];
				dfs(to,p[i],2);
				int j=i;
				int tmp=0;
				while(p[j]!=en)
				{
					tmp++;
					j=(j-2+len)%len+1;
				}
				tmp++;
				printf("%d ",tmp);
				j=i;
				while(p[j]!=en)
				{
					printf("%d ",p[j]);
					j=(j-2+len)%len+1;
				}
				printf("%d\n",en);
				printf("%d ",len-tmp+2);
				j=i;
				while(p[j]!=en)
				{
					printf("%d ",p[j]);
					j=j%len+1;
				}
				printf("%d\n",en);
				exit(0);
			}
		}
		for(int i=0;i<num;i++)
		{
			#undef e
			int u=e[SCC[t][i]<<1].to;
			int v=e[SCC[t][i]<<1|1].to;
			#define e E
			d[u]=d[v]=head[u]=head[v]=flag[u]=flag[v]=used[u]=used[v]=0;
		}
	}
	#undef e
}G;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)Tarjan(i,-1);
	for(int t=1;t<=scc;t++)G.solve(t);
	printf("NO\n");
	return 0;
}