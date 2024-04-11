#include<bits/stdc++.h>
#define inf 2000000001
#define maxn 100005
using namespace std;
int n,s,l;
int a[maxn];
struct SegmentTree1
{
	int minv[maxn<<2];
	void pushup(int rt)
	{
		minv[rt]=min(minv[rt<<1],minv[rt<<1|1]); 
	}
	void build(int rt,int l,int r)
	{
		int mid=(l+r)>>1;
		minv[rt]=inf;
		if(l==r)return;
		build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
		pushup(rt); 
	}
	void update(int rt,int l,int r,int p,int v)
	{
		int mid=(l+r)>>1;
		if(l==r)
		{
			minv[rt]=v;
			return;
		}
		if(p<=mid)update(rt<<1,l,mid,p,v);
		else update(rt<<1|1,mid+1,r,p,v);
		pushup(rt);
	}
	int query(int rt,int l,int r,int ql,int qr)
	{
		int ans=inf;
		if(ql<=l&&r<=qr)return minv[rt];
		int mid=(l+r)>>1;
		if(ql<=mid)ans=min(ans,query(rt<<1,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,query(rt<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}sgt1;
struct SegmentTree2
{
	int maxv[maxn<<2],minv[maxn<<2];
	void pushup(int rt)
	{
		maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
		minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
	}
	void build(int rt,int l,int r)
	{
		int mid=(l+r)>>1;
		if(l==r)
		{
			maxv[rt]=minv[rt]=a[l];
			return;
		}
		build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	int querymin(int rt,int l,int r,int ql,int qr)
	{
		int ans=inf;
		if(ql<=l&&r<=qr)return minv[rt];
		int mid=(l+r)>>1;
		if(ql<=mid)ans=min(ans,querymin(rt<<1,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,querymin(rt<<1|1,mid+1,r,ql,qr));
		return ans; 
	}
	int querymax(int rt,int l,int r,int ql,int qr)
	{
		int ans=-inf;
		if(ql<=l&&r<=qr)return maxv[rt];
		int mid=(l+r)>>1;
		if(ql<=mid)ans=max(ans,querymax(rt<<1,l,mid,ql,qr));
		if(qr>mid)ans=max(ans,querymax(rt<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}sgt2;
int dp[maxn];
int get(int l,int r,int x)
{
	int ans=r+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(sgt2.querymax(1,1,n,mid+1,x)-sgt2.querymin(1,1,n,mid+1,x)<=s)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&s,&l);
	n++;
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	a[1]=a[2];
	sgt1.build(1,1,n);
	sgt2.build(1,1,n);
	sgt1.update(1,1,n,1,0);
	for(int i=2;i<=n;++i)dp[i]=inf;
	for(int i=l+1;i<=n;++i)
	{
		int R=i-l;
		int L=get(1,R,i);
		if(L>R)dp[i]=inf;
		else dp[i]=sgt1.query(1,1,n,L,R)+1;
		sgt1.update(1,1,n,i,dp[i]);
	}
	if(dp[n]>=inf)dp[n]=-1;
	printf("%d\n",dp[n]);
	return 0;
}