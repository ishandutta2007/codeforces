#include<bits/stdc++.h>
using namespace std;
const int INF=10000000;
const int N=1005;
const int dx[]={0,-1,1,0},dy[]={-1,0,0,1};
int dis[N][N][4];
char mp[N][N];
vector<pair<int,int>> a[4];
queue<pair<pair<int,int>,int>> q;
int main()
{
	int n,m,x,y,kx,ky,kdis,ans,sum,d1_2=INF,d1_3=INF,d2_3=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=3;k++)
				dis[i][j][k]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]>='1'&&mp[i][j]<='3')
				a[mp[i][j]-'0'].push_back(make_pair(i,j));
	while(!q.empty())
		q.pop();
	for(int i=0;i<a[1].size();i++)
	{
		q.push(make_pair(make_pair(a[1][i].first,a[1][i].second),0));
		dis[a[1][i].first][a[1][i].second][1]=0;
	}
	while(!q.empty())
	{
		pair<pair<int,int>,int> k=q.front();
		q.pop();
		kx=k.first.first;
		ky=k.first.second;
		kdis=k.second;
		for(int i=0;i<4;i++)
		{
			x=kx+dx[i];
			y=ky+dy[i];
			if(x<1||x>n||y<1||y>m||mp[x][y]=='#')
				continue;
			if(kdis+1<dis[x][y][1])
			{
				dis[x][y][1]=kdis+1;
				q.push(make_pair(make_pair(x,y),kdis+1));
			}
		}
	}
	while(!q.empty())
		q.pop();
	for(int i=0;i<a[2].size();i++)
	{
		q.push(make_pair(make_pair(a[2][i].first,a[2][i].second),0));
		dis[a[2][i].first][a[2][i].second][2]=0;
	}
	while(!q.empty())
	{
		pair<pair<int,int>,int> k=q.front();
		q.pop();
		kx=k.first.first;
		ky=k.first.second;
		kdis=k.second;
		for(int i=0;i<4;i++)
		{
			x=kx+dx[i];
			y=ky+dy[i];
			if(x<1||x>n||y<1||y>m||mp[x][y]=='#')
				continue;
			if(kdis+1<dis[x][y][2])
			{
				dis[x][y][2]=kdis+1;
				q.push(make_pair(make_pair(x,y),kdis+1));
			}
		}
	}
	while(!q.empty())
		q.pop();
	for(int i=0;i<a[3].size();i++)
	{
		q.push(make_pair(make_pair(a[3][i].first,a[3][i].second),0));
		dis[a[3][i].first][a[3][i].second][3]=0;
	}
	while(!q.empty())
	{
		pair<pair<int,int>,int> k=q.front();
		q.pop();
		kx=k.first.first;
		ky=k.first.second;
		kdis=k.second;
		for(int i=0;i<4;i++)
		{
			x=kx+dx[i];
			y=ky+dy[i];
			if(x<1||x>n||y<1||y>m||mp[x][y]=='#')
				continue;
			if(kdis+1<dis[x][y][3])
			{
				dis[x][y][3]=kdis+1;
				q.push(make_pair(make_pair(x,y),kdis+1));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='1')
			{
				d1_2=min(d1_2,dis[i][j][2]);
				d1_3=min(d1_3,dis[i][j][3]);
			}
			if(mp[i][j]=='2')
			{
				d1_2=min(d1_2,dis[i][j][1]);
				d2_3=min(d2_3,dis[i][j][3]);
			}
			if(mp[i][j]=='3')
			{
				d1_3=min(d1_3,dis[i][j][1]);
				d2_3=min(d2_3,dis[i][j][2]);
			}
		}
	}
	ans=min(min(d1_2+d1_3,d1_2+d2_3),d1_3+d2_3);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum=0;
			for(int k=1;k<=3;k++)
				sum+=dis[i][j][k];
			ans=min(ans,sum);
		}
	}
	printf("%d\n",ans>=INF?-1:ans-2);
	return 0;
}