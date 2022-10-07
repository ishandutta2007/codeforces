#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int n,m,k,ans,d[200005],cnt[200005][10][10];
set<pair<int,int> >f[15][15];
vector<pair<int,int> >out[200005];
bool flag[15][15];
int vis[15][15];
void dfs(int step)
{
	if(step==k+1)
	{
		ans++;
		return;
	}
	for(int i=1;i<=step;i++)
	{
		if(flag[step][i]||vis[step][i])continue;
		vis[step][i]=1;
		for(auto x:f[step][i])vis[x.first][x.second]++;
		dfs(step+1);
		vis[step][i]=0;
		for(auto x:f[step][i])vis[x.first][x.second]--;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		out[u].push_back(make_pair(l,v));
		d[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		sort(out[i].begin(),out[i].end());
		for(int j=0;j<d[i];j++)
		  cnt[out[i][j].second][d[i]][j+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=k;x++)
		for(int y=1;y<=x;y++)
		{
			if(!cnt[i][x][y])continue;
			if(cnt[i][x][y]>=2)
			{
				flag[x][y]=1;
				continue;
			}
			for(int xx=x+1;xx<=k;xx++)
			for(int yy=1;yy<=xx;yy++)
			  if(cnt[i][xx][yy])
			    f[x][y].insert(make_pair(xx,yy));
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}