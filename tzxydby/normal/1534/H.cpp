#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,dp[N],ans,id[N],r,h[2];
vector<int>e[N];
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
void sol(int u,int f)
{
	dp[u]=1;
	vector<int>a;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		sol(v,u);
		a.push_back(dp[v]);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
		dp[u]=max(dp[u],a[i]+i);
}
void dfs(int u,int f,int g)
{
	vector<pair<int,int>>a;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		a.emplace_back(dp[v],v);
	}
	if(f)
		a.emplace_back(g,0);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int m=a.size();
	for(int i=0;i<m;i++)
		id[a[i].second]=i;
	int mx=0;
	for(int i=1;i<m;i++)
		mx=max(mx,a[i].first+i-1);
	mx+=a[0].first;
	ans=max(ans,mx);
	for(int i=0;i<m;i++)
		a[i].first+=i;
	vector<pair<int,int>>pr=a,sf=a;
	for(int i=1;i<m;i++)
		pr[i]=max(pr[i],pr[i-1]);
	for(int i=m-2;i>=0;i--)
		sf[i]=max(sf[i],sf[i+1]);
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		int mx=1,d=id[v];
		if(d!=0)
			mx=max(mx,pr[d-1].first);
		if(d!=m-1)
			mx=max(mx,sf[d+1].first-1);
		dfs(v,u,mx);
	}
}
int zyb(int u,int f)
{
	vector<pair<int,int>>a;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		a.emplace_back(dp[v],v);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	if(!a.size())
		return ask(u);
	if(f)
	{
		for(int i=0;i<a.size();i++)
		{
			int v=a[i].second,x=zyb(v,u);
			if(x!=u)
				return x;
		}
		return u;
	}
	vector<int>ans;
	for(int i=0;i<a.size();i++)
	{
		int v=a[i].second,x=zyb(v,u);
		if(x!=u)
		{
			ans.push_back(x);
			if(ans.size()==2)
				break;
		}
	}
	while(ans.size()<2)
		ans.push_back(u);
	printf("! %d %d\n",ans[0],ans[1]);
	return 0;
}
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("0\n");
		fflush(stdout);
		printf("! 1 1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	sol(1,0);
	dfs(1,0,0);
	printf("%d\n",ans);
	fflush(stdout);
	scanf("%d",&r);
	sol(r,0);
	zyb(r,0);
	return 0;
}