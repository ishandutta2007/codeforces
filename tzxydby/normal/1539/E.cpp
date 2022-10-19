#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[2][N],b[2][N],c[N];
struct seg1
{
	int mx[N<<2];
	void build(int k,int l,int r,int t)
	{
		if(l==r)
		{
			mx[k]=a[t][l];
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid,t);
		build(k<<1|1,mid+1,r,t);
		mx[k]=max(mx[k<<1],mx[k<<1|1]);
	}
	int ask(int k,int l,int r,int a,int b,int v)
	{
		if(a>b||mx[k]<=v)
			return n+1;
		if(l==r)
			return l;
		if(l==a&&r==b)
		{
			int mid=l+r>>1;
			if(mx[k<<1]>v) return ask(k<<1,l,mid,a,mid,v);
			else return ask(k<<1|1,mid+1,r,mid+1,b,v);
		}
		int mid=l+r>>1;
		if(b<=mid) return ask(k<<1,l,mid,a,b,v);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b,v);
		else
		{
			int t=ask(k<<1,l,mid,a,mid,v);
			if(t==n+1) return ask(k<<1|1,mid+1,r,mid+1,b,v);
			else return t;
		}
	}
}s1,s3;
struct seg2
{
	int mn[N<<2];
	void build(int k,int l,int r,int t)
	{
		if(l==r)
		{
			mn[k]=b[t][l];
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid,t);
		build(k<<1|1,mid+1,r,t);
		mn[k]=min(mn[k<<1],mn[k<<1|1]);
	}
	int ask(int k,int l,int r,int a,int b,int v)
	{
		if(a>b||mn[k]>=v)
			return n+1;
		if(l==r)
			return l;
		if(l==a&&r==b)
		{
			int mid=l+r>>1;
			if(mn[k<<1]<v) return ask(k<<1,l,mid,a,mid,v);
			else return ask(k<<1|1,mid+1,r,mid+1,b,v);
		}
		int mid=l+r>>1;
		if(b<=mid) return ask(k<<1,l,mid,a,b,v);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b,v);
		else
		{
			int t=ask(k<<1,l,mid,a,mid,v);
			if(t==n+1) return ask(k<<1|1,mid+1,r,mid+1,b,v);
			else return t;
		}
	}
}s2,s4;
struct seg3
{
	int tg[N<<2];
	void build(int k,int l,int r)
	{
		tg[k]=0;
		if(l==r)
			return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	void upd(int k,int l,int r,int a,int b,int v)
	{
		if(l==a&&r==b)
		{
			tg[k]=v;
			return;
		}
		int mid=l+r>>1;
		if(b<=mid) upd(k<<1,l,mid,a,b,v);
		else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
		else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
	}
	int ask(int k,int l,int r,int x)
	{
		if(tg[k])
			return tg[k];
		if(l==r)
			return 0;
		int mid=l+r>>1;
		if(x<=mid) return ask(k<<1,l,mid,x);
		else return ask(k<<1|1,mid+1,r,x);
	}
}dp0,dp1;
int dl[N],dr[N],al[N],ar[N],ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&c[i],&a[0][i],&b[0][i],&a[1][i],&b[1][i]);
	s1.build(1,1,n,0);
	s2.build(1,1,n,0);
	s3.build(1,1,n,1);
	s4.build(1,1,n,1);
	dp0.build(1,1,n);
	dp1.build(1,1,n);
	dl[n+1]=dr[n+1]=n+1;
	for(int i=n;i>=0;i--)
	{
		dl[i]=dl[i+1],dr[i]=dr[i+1];
		if(c[i]<a[0][i]||c[i]>b[0][i])
			dl[i]=i;
		if(c[i]<a[1][i]||c[i]>b[1][i])
			dr[i]=i;
		al[i]=dr[i+1];
		al[i]=min(al[i],s1.ask(1,1,n,i+1,n,c[i]));
		al[i]=min(al[i],s2.ask(1,1,n,i+1,n,c[i]));
		al[i]--;
		ar[i]=dl[i+1];
		ar[i]=min(ar[i],s3.ask(1,1,n,i+1,n,c[i]));
		ar[i]=min(ar[i],s4.ask(1,1,n,i+1,n,c[i]));
		ar[i]--;
	}
	for(int i=0;i<=n;i++)
	{
		if(((i==0)||dp0.ask(1,1,n,i))&&al[i]!=i)
			dp1.upd(1,1,n,i+1,al[i],i+1);
		if(((i==0)||dp1.ask(1,1,n,i))&&ar[i]!=i)
			dp0.upd(1,1,n,i+1,ar[i],i+1);
	}
	int v0=dp0.ask(1,1,n,n),v1=dp1.ask(1,1,n,n);
	if(v0)
	{
		puts("Yes");
		int x=n,c=0;
		while(1)
		{
			if(x==0)
				break;
			int y=(c?dp1:dp0).ask(1,1,n,x)-1;
			for(int i=y+1;i<=x;i++)
				ans[i]=c;
			x=y,c^=1;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	else if(v1)
	{
		puts("Yes");
		int x=n,c=1;
		while(1)
		{
			if(x==0)
				break;
			int y=(c?dp1:dp0).ask(1,1,n,x)-1;
			for(int i=y+1;i<=x;i++)
				ans[i]=c;
			x=y,c^=1;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	else
		puts("No");
	return 0;
}