#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,mx[N<<2],cm[N<<2],c[N<<2];
long long t1[N],t2[N];
void ad(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		t1[i]+=v,t2[i]+=1ll*x*v;
}
void add(int l,int r,int v)
{
	ad(l,v);
	ad(r+1,-v);
}
long long qry(int x)
{
	long long v=0;
	for(int i=x;i>=1;i-=i&(-i))
		v+=(x+1)*t1[i]-t2[i];
	return v;
}
long long ask(int l,int r)
{
	return qry(r)-qry(l-1);
}
void pu(int k)
{
	if(mx[k<<1]>mx[k<<1|1])
	{
		mx[k]=mx[k<<1];
		c[k]=c[k<<1];
		cm[k]=max(cm[k<<1],mx[k<<1|1]);
	}
	if(mx[k<<1]<mx[k<<1|1])
	{
		mx[k]=mx[k<<1|1];
		c[k]=c[k<<1|1];
		cm[k]=max(mx[k<<1],cm[k<<1|1]);
	}
	if(mx[k<<1]==mx[k<<1|1])
	{
		mx[k]=mx[k<<1];
		c[k]=c[k<<1]+c[k<<1|1];
		cm[k]=max(cm[k<<1],cm[k<<1|1]);
	}
}
void pd(int k)
{
	mx[k<<1]=min(mx[k<<1],mx[k]);
	mx[k<<1|1]=min(mx[k<<1|1],mx[k]);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		mx[k]=l,c[k]=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pu(k);
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(a>b) return;
	if(v>=mx[k]) return;
	if(l==a&&r==b)
	{
		if(cm[k]<v)
		{
			add(v+1,mx[k],-c[k]);
			mx[k]=v;
			return;
		}
		pd(k);
		int mid=l+r>>1;
		upd(k<<1,l,mid,a,mid,v);
		upd(k<<1|1,mid+1,r,mid+1,b,v);
		pu(k);
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
	pu(k);
}
void ch(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		add(l,mx[k],-1);
		mx[k]=v;
		add(l,mx[k],1);
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid) ch(k<<1,l,mid,x,v);
	else ch(k<<1|1,mid+1,r,x,v);
	pu(k);
}
int main()
{
	scanf("%d%d",&n,&q);
	build(1,1,n);
	add(1,n,1);
	while(q--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			upd(1,1,n,1,x-1,x-1);
			ch(1,1,n,x,y);
		}
		else
			printf("%lld\n",ask(x,y));
	}
	return 0;
}