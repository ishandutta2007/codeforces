#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=400005;
map<pair<int,int>,int>mp;
int n,m,vis[N],in[N];
vector<pair<int,int>>e[N],ans;
int id(int a,int b,int c,int d)
{
	int x=a*d,y=b*c;
	int g=__gcd(x,y);
	x/=g,y/=g;
	if(mp.count(make_pair(x,y)))
		return mp[make_pair(x,y)];
	return mp[make_pair(x,y)]=++m;
}
int dfs(int u)
{
	vis[u]=1,in[u]=1;
	int c=-1;
	for(auto i:e[u])
	{
		int v=i.first,x=i.second;
		if(vis[v])
		{
			if(!in[v])
			{
				if(c==-1)
					c=x;
				else
					ans.emplace_back(c,x),c=-1;
			}
			continue;
		}
		int y=dfs(v);
		if(y==-1)
		{
			if(c==-1)
				c=x;
			else
				ans.emplace_back(c,x),c=-1;
		}
		else
			ans.emplace_back(x,y);
	}
	in[u]=0;
	return c;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x=id(a+b,b,c,d),y=id(a,b,c+d,d);
		e[x].emplace_back(y,i);
		e[y].emplace_back(x,i);
	}
	for(int i=1;i<=m;i++)
		if(!vis[i])
			dfs(i);
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i.first<<' '<<i.second<<endl;
	return 0;
}//