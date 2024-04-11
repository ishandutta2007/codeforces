#include <bits/stdc++.h>
using namespace std;
int a[200005];
inline int FA(int x)
{
	for(int i=1;;i*=2)
		if(i>=x) return i-x;
}
vector <int> e[5000005];
unordered_map <int,int> mp;
int cnt;
int dep[5000005],id[5000005],ans,X,Y,out[5000005];
bitset <1000000005> vis;
inline void add(int x,int y)
{
	if(!mp[x]) mp[x]=++cnt;
	if(!mp[y]) mp[y]=++cnt;
	e[mp[x]].push_back(mp[y]);
}
inline void dfs(int u)
{
	int mx=0,cd=0;
	if(out[u]) mx=u;
	for(auto v:e[u])
	{
		dep[v]=dep[u]+1,dfs(v);
		if(dep[id[v]]>dep[mx]) cd=mx,mx=id[v];
		else if(dep[id[v]]>dep[cd]) cd=id[v];
	}
	if(ans<dep[mx]+dep[cd]-dep[u]*2)
		X=out[mx],Y=out[cd];
	ans=max(ans,dep[mx]+dep[cd]-dep[u]*2);
	id[u]=mx;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		int x=a[i];
		if(!mp[a[i]]) mp[a[i]]=++cnt;
		out[mp[a[i]]]=i;
		while(x)
		{
			int F=FA(x);
			if(!vis[x]) add(F,x),vis[x]=1;
			x=F;
		}
	}
	dfs(mp[0]);
	cout << X << " " << Y << " " << ans;
	return 0;
}