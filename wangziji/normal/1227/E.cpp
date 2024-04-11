#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize 2 
using namespace std;
vector <int> dis[1000005],a[1000005];
int fx[10]={-1,-1,-1,0,0,1,1,1},fy[10]={1,0,-1,1,-1,1,0,-1},n,m;
queue <pair<int,int> > q;
inline bool pd(int x)
{
	while(!q.empty())
		q.pop();
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			dis[i][j]=x+1;
			if(!a[i][j])
			{
				dis[i][j]=0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<=7;i++)
		{
			int tx=x+fx[i],ty=y+fy[i];
			if(tx<0||ty<0||tx>n+1||ty>m+1)
				continue;
			if(dis[tx][ty]<=dis[x][y]+1)
				continue;
			dis[tx][ty]=dis[x][y]+1;
			//if(dis[tx][ty]<=x+1)
				q.push({tx,ty});
		}
	}/* 
	cout << x << endl;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(dis[i][j]>5e8)
				dis[i][j]=9;
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/ 
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(dis[i][j]>x)
			{
				dis[i][j]=0;
				q.push({i,j});
			}
			else
				dis[i][j]=x+1;
		}
	}
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<=7;i++)
		{
			int tx=x+fx[i],ty=y+fy[i];
			if(tx<0||ty<0||tx>n+1||ty>m+1)
				continue;
			if(dis[tx][ty]<=dis[x][y]+1)
				continue;
			dis[tx][ty]=dis[x][y]+1;
			//if(dis[tx][ty]<=x+1)
				q.push({tx,ty});
		}
	}/* 
	cout << x << endl;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(dis[i][j]>5e8)
				dis[i][j]=9;
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/ 
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(a[i][j]==0&&dis[i][j]<=x)
				return 0;
			if(a[i][j]==1&&dis[i][j]>x)
				return 0;
		}
	}
	return 1;
}
int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			char t='*';
			if(i&&j&&i<=n&&j<=m)
				cin >> t;
			if(t=='X')
				a[i].push_back(1);
			else
				a[i].push_back(0);
			dis[i].push_back(0);
		}
	}
	int l=0,r=min(n,m),ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pd(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	cout << ans << endl;
	pd(ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!dis[i][j])
				cout << "X";
			else
				cout << ".";
		}
		puts("");
	}
	return 0;
}
//dlstxdy!