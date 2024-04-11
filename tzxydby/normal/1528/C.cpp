#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,c,f1[N],f2[N],bg[N],ed[N],tr[N<<2],tg[N<<2],vis[N],s,m;
vector<int>e[N],g[N];
int mg(int x,int y)
{
	if(x==y)
		return x;
	return -1;
}
void build(int k,int l,int r)
{
	tg[k]=0;
	if(l==r)
	{
		tr[k]=0;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=mg(tr[k<<1],tr[k<<1|1]);
}
void pd(int k)
{
	if(tg[k])
	{
		tr[k<<1]=tg[k<<1]=tg[k];
		tr[k<<1|1]=tg[k<<1|1]=tg[k];
		tg[k]=0;
	}
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]=tg[k]=v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=mg(tr[k<<1],tr[k<<1|1]);
}
int ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return mg(ask(k<<1,l,mid,a,mid),ask(k<<1|1,mid+1,r,mid+1,b));
}
void dfs1(int u)
{
	bg[u]=++c;
	for(auto v:g[u])
		dfs1(v);
	ed[u]=c;
}
void dfs2(int u)
{
	int t,f,x,z=0;
	x=ask(1,1,n,bg[u],ed[u]);
	if(x==-1)
		t=1;
	else if(x)
	{
		t=2;
		f=x;
		if(vis[f])
			z=1,s--,vis[f]=0;
		s++;
		vis[u]=1;
		upd(1,1,n,bg[u],ed[u],u);
	}
	else
	{
		t=3;
		s++;
		vis[u]=1;
		upd(1,1,n,bg[u],ed[u],u);
	}
	m=max(m,s);
	for(auto v:e[u])
		dfs2(v);
	if(t==2)
	{
		if(z)
			s++,vis[f]=1;
		s--;
		vis[u]=0;
		upd(1,1,n,bg[u],ed[u],f);
	}
	if(t==3)
	{
		s--;
		vis[u]=0;
		upd(1,1,n,bg[u],ed[u],0);
	}
}
void sol()
{
	scanf("%d",&n);
	build(1,1,n);
	c=s=m=0;
	for(int i=1;i<=n;i++)
		e[i].clear(),g[i].clear(),f1[i]=f2[i]=bg[i]=ed[i]=vis[i]=0;
	for(int i=2;i<=n;i++)
		scanf("%d",&f1[i]);
	for(int i=2;i<=n;i++)
		scanf("%d",&f2[i]);
	for(int i=2;i<=n;i++)
	{
		e[f1[i]].push_back(i);
		g[f2[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	printf("%d\n",m);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}