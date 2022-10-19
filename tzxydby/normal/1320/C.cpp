#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=1000005,inf=1000000;
struct zh
{
	int v,c;
	bool operator<(const zh k)const
	{
		return v<k.v;
	}
}a[N],b[N];
struct mos
{
	int v1,v2,c;
	bool operator<(const mos k)const
	{
		return v1<k.v1;
	}
}c[N];
int n,m,p,las=1;
long long tr[M<<2],tag[M<<2],ar[M],ans=-1e18;
void pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=ar[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int a,int b,long long v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	for(int i=1;i<=inf;i++)
		ar[i]=-1e18;
	for(int i=1;i<=n;i++)
		cin>>a[i].v>>a[i].c;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].v>>b[i].c;
		ar[b[i].v]=max((long long)-b[i].c,ar[b[i].v]);
	}
	for(int i=1;i<=p;i++)
		cin>>c[i].v1>>c[i].v2>>c[i].c;
	sort(a+1,a+n+1);
	sort(c+1,c+p+1);
	build(1,1,inf);
	for(int i=1;i<=n;i++)
	{
		while(las<=p&&c[las].v1<a[i].v)
		{
			if(c[las].v2!=inf)
				update(1,1,inf,c[las].v2+1,inf,c[las].c);
			las++;
		}
		ans=max(ans,tr[1]-a[i].c);
	}
	cout<<ans<<endl;
	return 0;
}