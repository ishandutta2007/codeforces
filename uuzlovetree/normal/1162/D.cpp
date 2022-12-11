#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n,m;
map<int,int> has[maxn];
struct edge
{
	int u,v;
}e[maxn<<1];
int main()
{
	scanf("%d%d",&n,&m);
	ll L=1;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		e[i].u=u;e[i].v=v;
		has[u][v]=1;has[v][u]=1;
	}
	bool ok=0;
	for(int k=1;k*k<=n;++k)if(n%k==0)
	{
		bool yes;
		L=k;yes=1;
		for(int i=1;i<=m;++i)
		{
			if(!has[(e[i].u+L)%n].count((e[i].v+L)%n))yes=0;
		}
		if(yes)
		{
			ok=1;break;
		}
		L=n/k;yes=1;
		if(k==1)yes=0;
		for(int i=1;i<=m;++i)
		{
			if(!has[(e[i].u+L)%n].count((e[i].v+L)%n))yes=0;
		}
		if(yes)
		{
			ok=1;break;
		}
	}
	if(ok)puts("Yes");
	else puts("No");
	return 0;
}