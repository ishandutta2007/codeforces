#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,nx,ny;
int vis[N][N];
char a[N][N];
vector<pair<char,pair<int,int>>>ans;
void dfs(int x,int y)
{
	vis[x][y]=1;
	int res=0;
	for(int i=0;i<4;i++)
	{
		int kx=x+dx[i],ky=y+dy[i];
		if(vis[kx][ky]||kx<1||kx>n||ky<1||ky>m||a[kx][ky]=='#')
			continue;
		dfs(kx,ky);
	}
	if(x!=nx||y!=ny)
	{
		ans.push_back(make_pair('D',make_pair(x,y)));
		ans.push_back(make_pair('R',make_pair(x,y)));
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='.')
				ans.push_back(make_pair('B',make_pair(i,j)));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'||vis[i][j])
				continue;
			nx=i;
			ny=j;
			dfs(nx,ny);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%c %d %d\n",ans[i].first,ans[i].second.first,ans[i].second.second);
	return 0;//
}