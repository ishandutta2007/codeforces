#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1000;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node
{
	int x,y;
};
char map[MAXN+5][MAXN+5];
int vis[MAXN+5][MAXN+5],flag[MAXN+5][MAXN+5],V[MAXN*MAXN+10],tot,F;
int n,m,k;
void Bfs(int x0,int y0)
{
	tot=1;
	queue<node>que;
	node p;p.x=x0;p.y=y0;
	que.push(p);
	vis[x0][y0]=1;
	flag[x0][y0]=++F;
	while(!que.empty())
	{
		node f=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int x1=f.x+dir[i][0];
			int y1=f.y+dir[i][1];
			if(x1<1||y1<1||x1>n||y1>m)
				continue;
			if(vis[x1][y1]!=0)
				continue;
			if(map[x1][y1]=='.')
			{
				tot++;
				node q;q.x=x1;q.y=y1;
				que.push(q);
				vis[x1][y1]=1;
				flag[x1][y1]=F;
			}
		}
	}
	//tot
	que.push(p);
	vis[x0][y0]=tot;
	while(!que.empty())
	{
		node f=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int x1=f.x+dir[i][0];
			int y1=f.y+dir[i][1];
			if(x1<1||y1<1||x1>n||y1>m)
				continue;
			if(vis[x1][y1]==1)
			{
				node q;q.x=x1;q.y=y1;
				que.push(q);
				vis[x1][y1]=tot;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]=='.'&&vis[i][j]==0)
				Bfs(i,j);
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d",vis[i][j]);
		printf("\n");
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int k=1;
			if(map[i][j]=='*')
			{
				if(!V[flag[i-1][j]])
				{
					k+=vis[i-1][j];
					V[flag[i-1][j]]=1;
				}
				if(!V[flag[i+1][j]])
				{
					k+=vis[i+1][j];
					V[flag[i+1][j]]=1;
				}
				if(!V[flag[i][j-1]])
				{
					k+=vis[i][j-1];
					V[flag[i][j-1]]=1;
				}
				if(!V[flag[i][j+1]])
				{
					k+=vis[i][j+1];
					V[flag[i][j+1]]=1;
				}
				V[flag[i-1][j]]=V[flag[i+1][j]]=V[flag[i][j-1]]=V[flag[i][j+1]]=0;
				printf("%d",k%10);
			}
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}