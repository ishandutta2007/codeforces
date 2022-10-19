#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,q,k,t[N],x[N],y[N],a[N],p[N],sz[N],st[N],tp,d,m;
vector<int>tr[N<<2];
int fa(int x)
{
	while(p[x]!=x)
		x=p[x];
	return x;
}
void undo(int u)
{
	while(tp>u)
	{
		int x=st[tp];
		sz[p[x]]-=sz[x];
		p[x]=x;
		tp--;
	}
}
void merge(int x,int y)
{
	x=fa(x),y=fa(y);
	if(x==y)
		return;
	tp++;
	if(sz[x]<sz[y])
	{
		p[x]=y;
		st[tp]=x;
		sz[y]+=sz[x];
	}
	else
	{	
		p[y]=x;
		st[tp]=y;
		sz[x]+=sz[y];
	}
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k].push_back(v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
}
void sol(int k,int l,int r)
{
	int u=tp;
	for(auto i:tr[k])
		merge(x[i],y[i]);
	if(l==r)
	{
		if(t[l]==2)
			printf("%d\n",sz[fa(x[l])]);
		undo(u);
		return;
	}
	int mid=l+r>>1;
	sol(k<<1,l,mid);
	sol(k<<1|1,mid+1,r);
	undo(u);
}
int main()
{
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
		p[i]=i,sz[i]=1;
	d=1;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&t[i]);
		if(t[i]==1)
			scanf("%d%d",&x[i],&y[i]);
		if(t[i]==2)
			scanf("%d",&x[i]);
		if(t[i]==3)
			a[d++]=i-1;
	}
	a[d]=q,m=d,d=1;
	for(int i=1;i<=q;i++)
	{
		if(t[i]==1)
			update(1,1,q,i,a[min(d+k-1,m)],i);
		if(t[i]==3)
			d++;
	}
	sol(1,1,q);
	return 0;
}