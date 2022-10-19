#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,m,k,sz[N],mx[N],vis[N],rt,pw[N]={1},iv[N]={0},ans;
vector<pair<int,int>>e[N],b;
vector<int>a,c;
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t=x;
	x=y,y=t-a/b*y;
}
int inv(int a,int k)
{
	int x,y;
	exgcd(a,k,x,y);
	x=(x+k)%k;
	return x;
}
void root(int u,int f)
{
	sz[u]=1,mx[u]=0;
	for(auto i:e[u])
	{
		int v=i.first;
		if(v==f||vis[v])
			continue;
		root(v,u);
		if(sz[v]>mx[u])
			mx[u]=sz[v];
		sz[u]+=sz[v];
	}
	mx[u]=max(mx[u],m-sz[u]);
	if(mx[u]<mx[rt])
		rt=u;
}
void dfs1(int u,int f,int p,int d)
{
	a.push_back(p);
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(v==f||vis[v])
			continue;
		dfs1(v,u,(p+w*d%k)%k,d*10%k);
	}
}
void dfs2(int u,int f,int p,int d)
{
	b.emplace_back(p,d);
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(v==f||vis[v])
			continue;
		dfs2(v,u,(p*10+w)%k,d+1);
	}
}
int cal(int u,int d)
{
	long long s=0;
	a.clear();
	b.clear();
	c.clear();
	if(!d)
	{
		dfs1(u,0,0,1);
		dfs2(u,0,0,0);
	}
	else
	{
		dfs1(u,0,d,10);
		dfs2(u,0,d,1);
	}
	for(auto i:b)
		c.push_back((k-i.first)*iv[i.second]%k);
	for(int i=0;i<a.size();i++)
		if(a[i]==c[i])
			s--;
	sort(c.begin(),c.end());
	for(auto i:a)
		s+=upper_bound(c.begin(),c.end(),i)-lower_bound(c.begin(),c.end(),i);
	return s;
}
void sol(int u)
{
	vis[u]=1;
	ans+=cal(u,0);
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(vis[v])
			continue;
		ans-=cal(v,w);
		rt=0,m=sz[v];
		root(v,0);
		sol(rt);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	if(k==1)
	{
		cout<<n*(n-1)<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]*10%k;
		iv[i]=inv(pw[i],k);
	}
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		w%=k;
		u++,v++;
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	mx[0]=1e9,m=n;
	root(1,0);
	sol(rt);
	cout<<ans<<endl;
	return 0;
}