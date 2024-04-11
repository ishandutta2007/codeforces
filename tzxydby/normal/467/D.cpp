#include<bits/stdc++.h>
#define mp make_pair 
#define fi first 
#define se second 
using namespace std;
unordered_map<string,int>d;
vector<int>a;
pair<int,int>dis[30005];
pair<int,int>f[30005];
vector<int>e[30005];
void dfs(int k)
{
	for(int i=0;i<e[k].size();i++)
	{
		int v=e[k][i];
		if(f[v]>f[k])
		{
			f[v]=f[k];
			dfs(v);
		} 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int m,n,cnt=0;
	string s,x,y;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+'a';
		int sum=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='r')
				sum++;
		if(d.find(s)==d.end())
			d[s]=++cnt;
		f[d[s]]=mp(sum,s.size());
		a.push_back(d[s]);
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int i=0;i<x.size();i++)
			if(x[i]>='A'&&x[i]<='Z')
				x[i]=x[i]-'A'+'a';
		int sum=0;
		for(int i=0;i<x.size();i++)
			if(x[i]=='r')
				sum++;
		if(d.find(x)==d.end())
			d[x]=++cnt;
		f[d[x]]=mp(sum,x.size());
		for(int i=0;i<y.size();i++)
			if(y[i]>='A'&&y[i]<='Z')
				y[i]=y[i]-'A'+'a';
		sum=0;
		for(int i=0;i<y.size();i++)
			if(y[i]=='r')
				sum++;
		if(d.find(y)==d.end())
			d[y]=++cnt;
		f[d[y]]=mp(sum,y.size());
		e[d[y]].push_back(d[x]);
	}
	for(int i=1;i<=cnt+1;i++)
		dfs(i);
	long long ans1=0,ans2=0;
	for(int i=0;i<a.size();i++)
	{
		ans1+=f[a[i]].fi;
		ans2+=f[a[i]].se;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}