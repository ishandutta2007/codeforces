#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,k,a[N],d[N],mx[N];
vector<int>e[N],t;
deque<int>dp[N];
int rd(){char c=getchar();int x=0;while(!(c>='0'&&c<='9'))c=getchar();while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x;}
void merge(deque<int>&p,deque<int>&q)
{
	if(p.size()>q.size())
		swap(p,q);
	t.assign(p.size(),0);
	for(int i=0;i<p.size();i++)
	{
		if(k-i<q.size())
			t[i]=p[i]+q[max(i,k-i)];
		else
			t[i]=p[i];
	}
	for(int i=0;i<p.size();i++)
		if(k-i<p.size())
			t[i]=max(t[i],q[i]+p[max(i,k-i)]);
	for(int i=0;i<p.size();i++)
		q[i]=max(q[i],t[i]);
	for(int i=p.size()-1-(p.size()==q.size());i>=0;i--)
		q[i]=max(q[i],q[i+1]);
	p.clear();
}
void dfs(int u,int f)
{
	dp[u].push_back(a[u]);
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		dp[v].push_front(0);
		merge(dp[v],dp[u]);
	}
}
signed main()
{
	n=rd(),k=rd()+1;
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<n;i++)
	{
		int u=rd(),v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",dp[1][0]);
	return 0;
}