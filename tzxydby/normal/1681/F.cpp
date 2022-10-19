#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ru[N],rv[N],rw[N],sz[N],f[N],su[N<<6],sv[N<<6],t;
vector<int>tr[N<<2],p[N];
long long ans;
void add(int k,int l,int r,int a,int b,int v)
{
	if(a>b)
		return;
	if(l==a&&r==b)
	{
		tr[k].push_back(v);
		return;
	}
	int md=l+r>>1;
	if(b<=md) add(k<<1,l,md,a,b,v);
	else if(a>md) add(k<<1|1,md+1,r,a,b,v);
	else add(k<<1,l,md,a,md,v),add(k<<1|1,md+1,r,md+1,b,v);
}
int fa(int u){return u==f[u]?u:fa(f[u]);}
void mg(int u,int v)
{
	u=fa(u),v=fa(v);
	if(u==v)
		return;
	if(sz[u]>sz[v])
		swap(u,v);
	t++;
	su[t]=u;
	sv[t]=v;
	f[u]=v;
	sz[v]+=sz[u];
}
void undo(int d)
{
	while(t>d)
	{
		int u=su[t],v=sv[t];
		t--;
		f[u]=u;
		sz[v]-=sz[u];
	}
}
void dfs(int k,int l,int r)
{
	int d=t;
	for(auto i:tr[k])
		mg(ru[i],rv[i]);
	if(l==r)
	{
		for(auto i:p[l])
		{
			int u=ru[i],v=rv[i];
			u=fa(u),v=fa(v);
			ans+=1ll*sz[u]*sz[v];
		}
	}
	else
	{
		int md=l+r>>1;
		dfs(k<<1,l,md);
		dfs(k<<1|1,md+1,r);
	}
	undo(d);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&ru[i],&rv[i],&rw[i]);
		p[rw[i]].push_back(i);
		add(1,1,n,1,rw[i]-1,i);
		add(1,1,n,rw[i]+1,n,i);
	}
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	dfs(1,1,n);
	printf("%lld\n",ans);
	return 0;
}