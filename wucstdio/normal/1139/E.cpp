#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[10005],match[10005],p[5005],c[5005],d,k[5005],t[5005],ans[5005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int maxx;
bool flag[10005];
bool dfs(int node)
{
	if(flag[node])return 0;
	if(!match[node])return 1;
	flag[node]=1;
	node=match[node];
	maxx=max(maxx,node);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==match[node])continue;
		int d=dfs(to);
		if(d)
		{
			match[node]=to;
			match[to]=node;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		scanf("%d",&k[i]);
		t[k[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		p[i]++;
		if(t[i]==0)
		{
			add(p[i]+m,c[i]);
			add(c[i],p[i]+m);
		}
	}
	ans[d+1]=1;
	for(int o=d;o>=1;o--)
	{
		ans[o]=ans[o+1];
		while(ans[o]<=5000)
		{
			if(match[ans[o]+m])
			{
				ans[o]++;
				continue;
			}
			maxx=0;
			for(int hd=head[ans[o]+m];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(dfs(to))
				{
					match[ans[o]+m]=to;
					match[to]=ans[o]+m;
					break;
				}
			}
			memset(flag,0,sizeof(flag));
			if(!match[ans[o]+m]&&maxx>ans[o]+m)
			{
				match[match[maxx]]=0,match[maxx]=0;
				for(int hd=head[ans[o]+m];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(dfs(to))
					{
						match[ans[o]+m]=to;
						match[to]=ans[o]+m;
						break;
					}
				}
				memset(flag,0,sizeof(flag));
			}
			if(match[ans[o]+m])ans[o]++;
			else break;
		}
		int i=k[o];
		add(p[i]+m,c[i]);
		add(c[i],p[i]+m);
	}
	for(int i=1;i<=d;i++)printf("%d\n",ans[i]-1);
	return 0;
}