#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2000005];
char _dir[2000005],*dir[1000005];
char _col[2000005],*col[1000005];
int t,n,m,edgenum,d[1000005],head[1000005],dep[1000005],pa[1000005],len[1000005],root[1000005];
bool vis[1000005];
queue<int>q;
vector<int>out[1000005];
vector<int>s[1000005];
bool flag[1000005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	d[v]++;
	head[u]=edgenum;
	out[v].push_back(u);
}
void dfs(int node,int r)
{
	vis[node]=1;
	root[node]=r;
	dep[node]=dep[pa[node]]+1;
	if(_col[node]=='0')s[r].push_back(node);
	for(auto to:out[node])
	{
		if(vis[to])
		{
			len[r]=dep[node];
			continue;
		}
		pa[to]=node;
		dfs(to,r);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++)head[i]=d[i]=dep[i]=pa[i]=vis[i]=0,out[i].clear(),s[i].clear();
		edgenum=0;
		for(int i=1;i<=n;i++)
		{
			dir[i]=_dir+(i-1)*m;
			col[i]=_col+(i-1)*m;
			scanf("%s",col[i]+1);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",dir[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(dir[i][j]=='U')add((i-1)*m+j,(i-2)*m+j);
				if(dir[i][j]=='D')add((i-1)*m+j,(i)*m+j);
				if(dir[i][j]=='L')add((i-1)*m+j,(i-1)*m+j-1);
				if(dir[i][j]=='R')add((i-1)*m+j,(i-1)*m+j+1);
			}
		}
		for(int i=1;i<=n*m;i++)
		{
			if(d[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				d[to]--;
				if(d[to]==0)q.push(to);
			}
		}
		int ans=0,ans2=0;
		for(int i=1;i<=n*m;i++)
		{
			if(d[i]&&!vis[i])
			{
				dfs(i,i);
				ans+=len[i];
				for(auto x:s[i])
				{
					if(!flag[dep[x]%len[i]])ans2++;
					flag[dep[x]%len[i]]=1;
				}
				for(auto x:s[i])flag[dep[x]%len[i]]=0;
			}
		}
		printf("%d %d\n",ans,ans2);
	}
	return 0;
}