#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],p[N];
long long ans;
struct nd{int m0,m1,c;};
inline nd operator+(nd a,nd b)
{
	if(a.m0<b.m0)
		swap(a,b);
	if(a.m0==b.m0)
		return {a.m0,max(a.m1,b.m1),a.c+b.c};
	else
		return {a.m0,max(a.m1,b.m0),a.c};
};
struct seg
{
	int b[N];
	void add(int x,int v)
	{
		for(int i=x;i<=n;i+=i&(-i))
			b[i]+=v;
	}
	int sum(int x)
	{
		int v=0;
		for(int i=x;i;i-=i&(-i))
			v+=b[i];
		return v;
	}
	nd tr[N<<2];
	int tag[N<<2];
	void pt(int x,int y)
	{
		if(tr[x].m0>tr[y].m0)
			tr[x].m0=tr[y].m0;
	}
	void pd(int k)
	{
		if(tag[k]>tr[k].m0)
		{
			pt(k<<1,k);
			pt(k<<1|1,k);
			tag[k]=tr[k].m0;
		}
	}
	void pu(int k)
	{
		tr[k]=tr[k<<1]+tr[k<<1|1];
		tag[k]=tr[k].m0;
	}
	void build(int k,int l,int r)
	{
		tag[k]=1e9;
		if(l==r)
			return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	void upd(int k,int l,int r,int a,int b,int v)
	{
		int mid=l+r>>1;
		if(l==a&&r==b)
		{
			if(v>=tr[k].m0)
				return;
			if(v<tr[k].m1)
			{
				pd(k);
				upd(k<<1,l,mid,a,mid,v);
				upd(k<<1|1,mid+1,r,mid+1,b,v);
				pu(k);
			}
			else
			{
				ans-=1ll*tr[k].c*(sum(tr[k].m0)-sum(v));
				tr[k].m0=v;
			}
			return;
		}
		pd(k);
		if(b<=mid) upd(k<<1,l,mid,a,b,v);
		else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
		else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
		pu(k);
	}
	void ch(int k,int l,int r,int x)
	{
		if(l==r)
		{
			tr[k]={n,0,1};
			return;
		}
		pd(k);
		int mid=l+r>>1;
		if(x<=mid) ch(k<<1,l,mid,x);
		else ch(k<<1|1,mid+1,r,x);
		pu(k);
	}
}s1,s2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	s1.build(1,1,n);
	s2.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		if(x>1) s1.upd(1,1,n,1,x-1,x-1);
		if(x<n) s2.upd(1,1,n,1,n-x,n-x);
		s1.add(x,1);
		s2.add(n-x+1,1);
		s1.ch(1,1,n,x);
		s2.ch(1,1,n,n-x+1);
		ans+=i;
		printf("%lld\n",ans);
	}
	return 0;
}