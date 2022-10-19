#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,a[N],b[N],pr[N],sf[N],st[N],tp;
long long tr[N<<2],ans[N];
struct nd{int l,r,d;};
vector<int>p[N];
vector<nd>q[N];
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=LLONG_MAX;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void upd(int k,int l,int r,int x,long long v)
{
	if(l==r)
	{
		tr[k]=min(tr[k],v);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x,v);
	else upd(k<<1|1,mid+1,r,x,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
long long ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return min(ask(k<<1,l,mid,a,mid),ask(k<<1|1,mid+1,r,mid+1,b));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q[r].push_back({l,r,i});
	}
	tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp&&b[st[tp]]>b[i])
			tp--;
		pr[i]=tp?st[tp]:-1;
		st[++tp]=i;	
	}
	tp=0;
	for(int i=n;i>=1;i--)
	{
		while(tp&&b[st[tp]]>b[i])
			tp--;
		sf[i]=tp?st[tp]:-1;
		st[++tp]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(pr[i]!=-1)
			p[i].push_back(pr[i]);
		if(sf[i]!=-1)
			p[sf[i]].push_back(i);
	}
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(auto j:p[i])
			upd(1,1,n,j,1ll*(a[i]-a[j])*(b[i]+b[j]));
		for(auto j:q[i])
			ans[j.d]=ask(1,1,n,j.l,j.r);
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}