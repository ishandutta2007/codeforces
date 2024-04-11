#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
int n,m,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},tox,toy;
bool vis[51][51];
char a[51][51];
void dfs(int x,int y,char color,int step)
{
	if(step>=3&&((x==tox&&y==toy-1)||(x==tox&&y==toy+1)||(x==tox-1&&y==toy)||(x==tox+1&&y==toy)))
	{
		printf("Yes");
		exit(0);
	}
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<=0||tx>n||ty<=0||toy>m||vis[tx][ty]||a[tx][ty]!=color)
		{
			continue;
		}
		dfs(tx,ty,color,step+1);
	}
	vis[x][y]=0;
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
		}
		getchar();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				tox=i;
				toy=j;
				dfs(i,j,a[i][j],0);
			}
		}
	}
	printf("No");
	return 0;
}