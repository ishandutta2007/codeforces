#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n;
int bx[maxn][maxn],by[maxn][maxn];
char Ans[maxn][maxn];
bool vis[maxn][maxn];
void bfs(int sx,int sy)
{
	queue< pair<int,int> > q;
	Ans[sx][sy]='X';
	q.push(make_pair(sx,sy));
	vis[sx][sy]=1;
	while(!q.empty())
	{
		pair<int,int> u=q.front();q.pop();
		int x=u.first,y=u.second;
		if(bx[x-1][y]==sx&&by[x-1][y]==sy&&!vis[x-1][y])Ans[x-1][y]='D',vis[x-1][y]=1,q.push(make_pair(x-1,y));
		if(bx[x+1][y]==sx&&by[x+1][y]==sy&&!vis[x+1][y])Ans[x+1][y]='U',vis[x+1][y]=1,q.push(make_pair(x+1,y));
		if(bx[x][y-1]==sx&&by[x][y-1]==sy&&!vis[x][y-1])Ans[x][y-1]='R',vis[x][y-1]=1,q.push(make_pair(x,y-1));
		if(bx[x][y+1]==sx&&by[x][y+1]==sy&&!vis[x][y+1])Ans[x][y+1]='L',vis[x][y+1]=1,q.push(make_pair(x,y+1));
	}
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	if(bx[x-1][y]==-1&&!vis[x-1][y])Ans[x-1][y]='D',dfs(x-1,y);
	if(bx[x+1][y]==-1&&!vis[x+1][y])Ans[x+1][y]='U',dfs(x+1,y);
	if(bx[x][y-1]==-1&&!vis[x][y-1])Ans[x][y-1]='R',dfs(x,y-1);
	if(bx[x][y+1]==-1&&!vis[x][y+1])Ans[x][y+1]='L',dfs(x,y+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)scanf("%d%d",&bx[i][j],&by[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(bx[i][j]==i&&by[i][j]==j)
		{
			bfs(i,j);
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(bx[i][j]==-1&&!vis[i][j])
		{
			if(bx[i-1][j]!=-1&&bx[i+1][j]!=-1&&bx[i][j-1]!=-1&&bx[i][j+1]!=-1)continue;
			if(bx[i-1][j]==-1)Ans[i][j]='U',dfs(i,j);
			else if(bx[i+1][j]==-1)Ans[i][j]='D',dfs(i,j);
			else if(bx[i][j-1]==-1)Ans[i][j]='L',dfs(i,j);
			else if(bx[i][j+1]==-1)Ans[i][j]='R',dfs(i,j);
		}
	bool yes=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(Ans[i][j]<'A'||Ans[i][j]>'Z')yes=0;
	if(!yes)puts("INVALID");
	else
	{
		puts("VALID");
		for(int i=1;i<=n;++i)printf("%s\n",Ans[i]+1);
	}
}