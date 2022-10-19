#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int dis[N][N];
char mp[N][N];
queue<pair<int,int>>q;
int main()
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	int n,m,sx,sy,ex,ey,kx,ky,x,y,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='E')
			{
				ex=i;
				ey=j;
			}
			if(mp[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
		}
	}
	dis[ex][ey]=0;
	q.push(make_pair(ex,ey));
	while(!q.empty())
	{
		pair<int,int>k=q.front();
		q.pop();
		kx=k.first;
		ky=k.second;
		for(int i=0;i<4;i++)
		{
			x=kx+dx[i];
			y=ky+dy[i];
			if(x<1||x>n||y<1||y>m||mp[x][y]=='T')
				continue;
			if(dis[kx][ky]+1<dis[x][y])
			{
				dis[x][y]=dis[kx][ky]+1;
				q.push(make_pair(x,y));
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]>='1'&&mp[i][j]<='9'&&dis[i][j]<=dis[sx][sy])
				sum+=mp[i][j]-'0';
	printf("%d\n",sum);
	return 0;
}
//