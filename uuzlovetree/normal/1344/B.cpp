#include<bits/stdc++.h>
#define maxn 1005 
using namespace std;
int n,m;
char a[maxn][maxn];
bool vis[maxn][maxn];
int id[maxn][maxn],cnt;
void dfs(int x,int y)
{
	if(a[x][y]!='#')return;
	if(vis[x][y])return;
	vis[x][y]=1;
	id[x][y]=cnt;
	dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1); 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)if(a[i][j]=='#'&&(!vis[i][j]))
		{
			++cnt;
			dfs(i,j);
		}
	bool yes=1,y1=0,y2=0;
	for(int i=1;i<=n;++i)
	{
		int lst=0;
		for(int j=1;j<=m;++j)if(a[i][j]=='#')
		{
			if(!lst)lst=j;
			else
			{
				if(j==lst+1)lst=j;
				else yes=0;
			}
		}
		if(!lst)y1=1;
	}
	for(int j=1;j<=m;++j)
	{
		int lst=0;
		for(int i=1;i<=n;++i)if(id[i][j])
		{
			if(!lst)lst=i;
			else
			{
				if(i==lst+1)lst=i;
				else yes=0;
			}
		}
		if(!lst)y2=1;
	}
	if(y1!=y2)yes=0;
	if(!yes)puts("-1");
	else printf("%d\n",cnt);
}