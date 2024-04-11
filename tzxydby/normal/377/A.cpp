#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,k;
char a[N][N];
bool vis[N][N];
vector<pair<int,int>>ord;
void dfs(int x,int y)
{
	vis[x][y]=1;
	ord.push_back(make_pair(x,y));
	for(int i=0;i<4;i++)
	{
		int kx=x+dx[i],ky=y+dy[i];
		if(vis[kx][ky]||kx<1||kx>n||ky<1||ky>m||a[kx][ky]=='#')
			continue;
		dfs(kx,ky);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
			{
				dfs(i,j);
				reverse(ord.begin(),ord.end());
				for(int i=0;i<k;i++)
					a[ord[i].first][ord[i].second]='X';
				for(int i=1;i<=n;i++)
					printf("%s\n",a[i]+1);
				return 0;
			}
		}
	}
	return 0;
}//