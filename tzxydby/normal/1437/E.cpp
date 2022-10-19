#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],tr[N<<2],t1[N<<2],t2[N<<2],ans=1e9;
vector<int>v;
void build(int k,int l,int r)
{
	t1[k]=-233,tr[k]=1e9;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushdown(int k)
{
	if(t1[k]!=-233)
	{
		tr[k<<1]=t1[k];
		t1[k<<1]=t1[k];
		tr[k<<1|1]=t1[k];
		t1[k<<1|1]=t1[k];
		t1[k]=-233;
	}
	if(t2[k])
	{
		tr[k<<1]+=t2[k];
		t2[k<<1]+=t2[k];
		tr[k<<1|1]+=t2[k];
		t2[k<<1|1]+=t2[k];
		t2[k]=0;
	}
}
void add(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		t2[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]=v;
		t1[k]=v;
		t2[k]=0;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return min(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]-i);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(v.begin(),v.end(),a[i]-i)-v.begin()+1;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		b[x]=1;
	}
	build(1,1,n);
	update(1,1,n,1,1,-1);
	for(int i=1;i<=n;i++)
	{
		add(1,1,n,1,n,1);
		int dp=query(1,1,n,1,a[i]);
		if(b[i])
			update(1,1,n,1,n,1e9);
		update(1,1,n,a[i],a[i],dp-1);
	}
	add(1,1,n,1,n,1);
	int ans=query(1,1,n,1,n);
	if(ans>=1e9)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}