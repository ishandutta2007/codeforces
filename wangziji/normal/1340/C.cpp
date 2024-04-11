#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>
#pragma GCC optimize 2
using namespace std;
int dis[11000005];
bitset <11000005> vis;
vector <pair<int,int> > e;
vector <int> qwq;
int a[10005];
queue <pair<int,int> > q;
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i];
		qwq.push_back(i);
	}
	int g,r;
	cin >> g >> r;
	sort(a+1,a+m+1);
/*	for(int i=1;i<m;i++)
	{
		for(int j=0;j<=g;j++)
		{
			if(a[i+1]-a[i]<=j)
			{
				e[i*(g+1)+j].push_back({(i+1)*(g+1)+j-a[i+1]+a[i],a[i+1]-a[i]}),
				e[(i+1)*(g+1)+j].push_back({i*(g+1)+j-a[i+1]+a[i],a[i+1]-a[i]});
			}
		}
	//	cout << i*(g+1) << " " << i*(g+1)+g << "*\n";
	//	e[i*(g+1)].push_back({i*(g+1)+g,r});
	}*/
	for(int i=1;i<=m*(g+1)+g;i++) dis[i]=2e9;
	dis[g+1+g]=0,q.push({0,g+1+g});
	for(int i=1;i<=m;i++)
	{
		while(!q.empty())
		{
			int x=q.front().second;
			q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			int i=x/(g+1),j=x-i*(g+1);
			e.clear();
			if(i<m&&a[i+1]-a[i]<=j) e.push_back({(i+1)*(g+1)+j-a[i+1]+a[i],a[i+1]-a[i]});
			if(i>1&&a[i]-a[i-1]<=j) e.push_back({(i-1)*(g+1)+j-a[i]+a[i-1],a[i]-a[i-1]}); 
			for(auto v:e)
			{
				if(dis[v.first]>dis[x]+v.second)
				{
					dis[v.first]=dis[x]+v.second;
					q.push({-dis[v.first],v.first});
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(dis[i*(g+1)+g]>dis[i*(g+1)]+r)
			{
				q.push({-dis[i*(g+1)+g],i*(g+1)+g});
				dis[i*(g+1)+g]=dis[i*(g+1)]+r;
			}
		}
		if(q.empty()) break;
	}
//	cout << dis[23] << " " << dis[32] << " " << dis[40] << "\n";
	int ans=2e9;
	for(int i=0;i<=g;i++)
		ans=min(ans,dis[m*(g+1)+i]);
	if(ans>1.5e9)
	{
		puts("-1");
	}else cout << ans;
	return 0;
}//dlstxdy!