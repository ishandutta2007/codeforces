#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,q,s[N],t[N],a[N],t1[N<<2],sz;
long long qs[N],qa[N],t2[N<<2],ls[N<<2],rs[N<<2];
vector<long long>p;
void upd(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		t1[k]=v;
		t2[k]=v*p[l];
		ls[k]=rs[k]=t2[k];
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x,v);
	else upd(k<<1|1,mid+1,r,x,v);
	t1[k]=t1[k<<1]+t1[k<<1|1];
	t2[k]=t2[k<<1]+t2[k<<1|1];
	ls[k]=ls[k<<1]+ls[k<<1|1]+t2[k<<1]*t1[k<<1|1];
	rs[k]=rs[k<<1|1]+rs[k<<1]+t2[k<<1|1]*t1[k<<1];
}
long long ql(int k,int l,int r,int x)
{
	if(l==r)
		return t2[k];
	int mid=l+r>>1;
	if(x<=t1[k<<1]) return ql(k<<1,l,mid,x);
	else return t2[k<<1]+ql(k<<1|1,mid+1,r,x-t1[k<<1]);
}
long long qr(int k,int l,int r,int x)
{
	if(l==r)
		return t2[k];
	int mid=l+r>>1;
	if(x<=t1[k<<1|1]) return qr(k<<1|1,mid+1,r,x);
	else return t2[k<<1|1]+qr(k<<1,l,mid,x-t1[k<<1|1]);
}
long long qls(int k,int l,int r,int x)
{
	if(l==r)
		return t2[k];
	int mid=l+r>>1;
	if(x<=t1[k<<1]) return qls(k<<1,l,mid,x);
	else return ls[k<<1]+qls(k<<1|1,mid+1,r,x-t1[k<<1])+(x-t1[k<<1])*t2[k<<1];
}
long long qrs(int k,int l,int r,int x)
{
	if(l==r)
		return t2[k];
	int mid=l+r>>1;
	if(x<=t1[k<<1|1]) return qrs(k<<1|1,mid+1,r,x);
	else return rs[k<<1|1]+qrs(k<<1,l,mid,x-t1[k<<1|1])+(x-t1[k<<1|1])*t2[k<<1|1];
}
void sol()
{
	if(sz==1)
	{
		puts("0");
		return;
	}
	int mx=sz/2;
	long long mv=qr(1,1,m,mx)-ql(1,1,m,mx+1);
	if(mv<=0)
	{
		printf("%lld\n",rs[1]-ls[1]);
		return;
	}
	int pl,pr;
	{
		int l=0,r=mx;
		while(r-l>1)
		{
			int m1=l+r>>1;
			if(qr(1,1,m,m1)-ql(1,1,m,m1+1)>=0)
				r=m1;
			else
				l=m1;
		}
		pl=r;
	}
	{
		int l=mx,r=sz;
		while(r-l>1)
		{
			int m1=l+r>>1;
			if(qr(1,1,m,m1)-ql(1,1,m,m1+1)>=0)
				l=m1;
			else
				r=m1;
		}
		pr=l+1;
	}
	long long ans=0;
	if(pl!=1)
		ans+=qrs(1,1,m,pl-1)-qls(1,1,m,pl-1);
	if(pr!=sz)
		ans+=(qrs(1,1,m,sz)-qrs(1,1,m,pr))-(qls(1,1,m,sz)-qls(1,1,m,pr));
	ans+=qr(1,1,m,pr)-ql(1,1,m,pl);
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d%d",&n,&q);
	p.push_back(0);
	for(int i=1;i<=n;i++)
		scanf("%lld",&qs[i]),p.push_back(qs[i]);
	for(int i=1;i<=q;i++)
		scanf("%d%lld",&t[i],&qa[i]),p.push_back(qa[i]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for(int i=1;i<=n;i++)
		s[i]=lower_bound(p.begin(),p.end(),qs[i])-p.begin();
	for(int i=1;i<=q;i++)
		a[i]=lower_bound(p.begin(),p.end(),qa[i])-p.begin();
	m=p.size()-1;
	for(int i=1;i<=n;i++)
		upd(1,1,m,s[i],1);
	sz=n;
	sol();
	for(int i=1;i<=q;i++)
	{
		if(t[i]==1)
			upd(1,1,m,a[i],1),sz++;
		else
			upd(1,1,m,a[i],0),sz--;
		sol();
	}
	return 0;
}