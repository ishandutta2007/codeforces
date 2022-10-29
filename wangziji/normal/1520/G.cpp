#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int a[2005][2005];
char vis[4000005];
long long dis1[4000005],dis2[4000005],n,m,w;
vector <pair<int,int> > e[4000005];
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
queue <int> q;
inline void add(int u,int v,int w)
{
	e[u].push_back({v,w});
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=m) if(a[i][j]!=-1&&a[i][j+1]!=-1) add(id(i,j),id(i,j+1),w),add(id(i,j+1),id(i,j),w);
			if(i!=n) if(a[i][j]!=-1&&a[i+1][j]!=-1) add(id(i,j),id(i+1,j),w),add(id(i+1,j),id(i,j),w);
		}
	}
	q.push(1);
	for(int i=0;i<=n*m;i++)
		dis1[i]=1e18;
	dis1[id(1,1)]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto X:e[x])
		{
			if(dis1[X.first]>dis1[x]+w)
				dis1[X.first]=dis1[x]+w,q.push(X.first);
		}
	}
	
	q.push(n*m);
	for(int i=0;i<=n*m;i++)
		dis2[i]=1e18;
	dis2[id(n,m)]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto X:e[x])
		{
			if(dis2[X.first]>dis2[x]+w)
				dis2[X.first]=dis2[x]+w,q.push(X.first);
		}
	}
	
	long long ans=dis1[id(n,m)],X=1e18,Y=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])X=min(X,dis1[id(i,j)]+a[i][j]);
			if(a[i][j])Y=min(Y,dis2[id(i,j)]+a[i][j]);
		}
	}
	ans=min(ans,X+Y);
	if(ans>1e17) ans=-1;
	cout << ans;
	return 0;
}