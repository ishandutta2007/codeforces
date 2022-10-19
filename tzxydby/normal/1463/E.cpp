#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,r,f[N],q[N],bg,ed,o[N],d[N];
vector<int>e[N],g[N],ans;
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x)
			e[x].push_back(i);
		else
			r=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		o[x]=y;
		int fx=fa(x),fy=fa(y);
		f[fy]=fx;
	}
	for(int u=1;u<=n;u++)
		for(auto v:e[u])
			if(fa(u)!=fa(v))
				g[fa(u)].push_back(fa(v)),d[fa(v)]++;
	for(int i=1;i<=n;i++)
		if(fa(i)==i&&!d[i])
			q[ed++]=i;
	while(bg<ed)
	{
		int u=q[bg++];
		int x=u;
		while(x)
		{
			ans.push_back(x);
			x=o[x];
			if(x==u)
			{
				puts("0");
				return 0;
			}
		}
		for(auto v:g[u])
		{
			d[v]--;
			if(!d[v])
				q[ed++]=v;
		}
	}
	if(ans.size()!=n)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		d[i]=1;
	d[r]=0;
	for(int i=0;i<n;i++)
	{
		int u=ans[i];
		if(d[u])
		{
			puts("0");
			return 0;
		}
		for(auto v:e[u])
			d[v]=0;
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}