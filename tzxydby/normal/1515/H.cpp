#include<bits/stdc++.h>
using namespace std;
const int N=200005,f=(1<<20)-1;
int n,q,u,m,lc[N<<6],rc[N<<6],tr[N<<6],t0[N<<6],t1[N<<6],t[N<<6];
void pt(int u,int p,int x)
{
	if(!u)
		return;
	if(x>>(p-1)&1)
		swap(lc[u],rc[u]);
	int v0=(t0[u]&(~x))|(t1[u]&x),v1=(t1[u]&(~x))|(t0[u]&x);
	t0[u]=v0,t1[u]=v1,t[u]^=x;
}
void pd(int u,int p)
{
	if(t[u])
	{
		pt(lc[u],p-1,t[u]);
		pt(rc[u],p-1,t[u]);
		t[u]=0;
	}
}
void pu(int u)
{
	tr[u]=tr[lc[u]]+tr[rc[u]];
	t0[u]=t0[lc[u]]|t0[rc[u]];
	t1[u]=t1[lc[u]]|t1[rc[u]];
}
int ins(int u,int p,int x)
{
	if(!u)
		u=++m;
	if(!p)
	{
		tr[u]=1;
		t0[u]=(x^f);
		t1[u]=x; 
		return u;
	}
	if(!(x>>(p-1)&1))
		lc[u]=ins(lc[u],p-1,x);
	else
		rc[u]=ins(rc[u],p-1,x);
	pu(u);
	return u;
}
void split(int &u,int &v,int p,int l,int r,int a,int b)
{
	if(b<=l||r<=a||!u)
	{
		v=0;
		return;
	}
	if(a<=l&&r<=b)
	{
		v=u;
		u=0;
		return;
	}
	pd(u,p);
	v=++m;
	int mid=l+r>>1;
	split(lc[u],lc[v],p-1,l,mid,a,b),split(rc[u],rc[v],p-1,mid,r,a,b);
	pu(u),pu(v);
}
void mg(int &u,int &v,int p)
{
	if(!u)
	{
		u=v;
		return;
	}
	if(v==0||p==0)
		return;
	pd(u,p),pd(v,p);
	mg(lc[u],lc[v],p-1);
	mg(rc[u],rc[v],p-1);
	pu(u);
}
void upd(int u,int p,int x)
{
	if(!u)
		return;
	if(!(x&t0[u]&t1[u]))
	{
		pt(u,p,x&t0[u]);
		return;
	}
	pd(u,p);
	if(x>>(p-1)&1)
	{
		pt(lc[u],p-1,1<<(p-1));
		mg(rc[u],lc[u],p-1);
		lc[u]=0;
	}
	upd(lc[u],p-1,x);
	upd(rc[u],p-1,x);
	pu(u);
}
int ask(int u,int p,int l,int r,int a,int b)
{
	if(b<=l||r<=a||!u)
		return 0;
	if(a<=l&&r<=b)
		return tr[u];
	pd(u,p);
	int mid=l+r>>1;
	return ask(lc[u],p-1,l,mid,a,b)+ask(rc[u],p-1,mid,r,a,b);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		u=ins(u,20,x);
	}
	while(q--)
	{
		int t,l,r,v,x;
		scanf("%d%d%d",&t,&l,&r);
		r++;
		if(t<=3)
		{
			scanf("%d",&x);
			split(u,v,20,0,f+1,l,r);
			if(t==1)
				pt(v,20,f),upd(v,20,x^f),pt(v,20,f);
			if(t==2)
				upd(v,20,x);
			if(t==3)
				pt(v,20,x);
			mg(u,v,20);
		}
		else
			printf("%d\n",ask(u,20,0,f+1,l,r));
	}
	return 0;
}