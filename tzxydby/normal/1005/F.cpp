#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k,q[N],bg,ed,d[N],c,a[N];
vector<pair<int,int>>e[N];
string s[N];
void dfs(int u)
{
	if(c>=k)
		return;
	if(u>n)
	{
		c++;
		for(int i=1;i<=m;i++)
			s[c]+=(char)('0'+a[i]);
		return;
	}
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(c>=k)
			return;
		if(d[v]+1==d[u])
		{
			a[w]=1;
			dfs(u+1);
			a[w]=0;
		}
	}
	if(c>=k)
		return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
	}
	for(int i=1;i<=n;i++)
		d[i]=-1;
	d[1]=0;
	q[ed++]=1;
	while(bg<ed)
	{
		int u=q[bg++];
		for(auto i:e[u])
		{
			int v=i.first,w=i.second;
			if(d[v]==-1)
			{
				d[v]=d[u]+1;
				q[ed++]=v;
			}
		}
	}
	dfs(2);
	cout<<c<<endl;
	for(int i=1;i<=c;i++)
		cout<<s[i]<<endl;
	return 0;
}