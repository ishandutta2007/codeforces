#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
int n,m,x,y,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[3001][3001];
bool vis[3001][3001],f[1501][1501];
void bfs()
{
	std::queue<std::pair<int,int> >q;
	q.push(std::make_pair(x,y));
	vis[x][y]=1;
	f[x][y]=1;
	while(!q.empty())
	{
		std::pair<int,int>now=q.front();
		q.pop();
		int nowx=now.first,nowy=now.second;
		for(int i=0;i<4;i++)
		{
			int tox=(nowx+dx[i]+n)%n,toy=(nowy+dy[i]+m)%m;
			if(a[tox][toy]=='#'||vis[tox][toy])
			{
				continue;
			}
			vis[tox][toy]=1;
			q.push(std::make_pair(tox,toy));
			tox%=(n/2);
			toy%=(m/2);
			if(f[tox][toy])
			{
				if(!tox||!toy||tox==n/2-1||toy==m/2-1)
				{
					printf("Yes");
					exit(0);
				}
			}
			f[tox][toy]=1;
		}
	}
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%c",&a[i][j]);
			a[i+n][j]=a[i][j+m]=a[i+n][j+m]=a[i][j];
			if(a[i][j]=='S')
			{
				x=i;
				y=j;
			}
		}
		getchar();
	}
	n*=2;
	m*=2;
	bfs();
	printf("No");
	return 0;
}