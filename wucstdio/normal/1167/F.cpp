#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Tree
{
	struct Node
	{
		ll sum;
		ll add;
	}tree[2000005];
	void pushup(int o)
	{
		tree[o].sum=tree[lson].sum+tree[rson].sum;
		if(tree[o].sum>=MOD)tree[o].sum-=MOD;
	}
	void pushdown(int o,int l,int r)
	{
		if(tree[o].add)
		{
			tree[lson].add+=tree[o].add;
			tree[rson].add+=tree[o].add;
			tree[lson].sum=(tree[lson].sum+tree[o].add*(mid-l+1))%MOD;
			tree[rson].sum=(tree[rson].sum+tree[o].add*(r-mid))%MOD;
			if(tree[lson].add>=MOD)tree[lson].add-=MOD;
			if(tree[rson].add>=MOD)tree[rson].add-=MOD;
			tree[o].add=0;
		}
	}
	void add(int o,int l,int r,int from,int to,ll v)
	{
		if(l>=from&&r<=to)
		{
			tree[o].add+=v;
			if(tree[o].add>=MOD)tree[o].add-=MOD;
			tree[o].sum=(tree[o].sum+v*(r-l+1))%MOD;
			return;
		}
		pushdown(o,l,r);
		if(from<=mid)add(lson,l,mid,from,to,v);
		if(to>mid)add(rson,mid+1,r,from,to,v);
		pushup(o);
	}
	ll query(int o,int l,int r,int from,int to)
	{
		if(from>to)return 0;
		if(l>=from&&r<=to)return tree[o].sum;
		pushdown(o,l,r);
		ll ans=0;
		if(from<=mid)ans+=query(lson,l,mid,from,to);
		if(to>mid)ans+=query(rson,mid+1,r,from,to);
		if(ans>=MOD)ans-=MOD;
		return ans;
	}
}T1,T2;
int n,a[500005],sa[500005];
ll ans,s;
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		T1.add(1,1,n,sa[i],n,sa[i]);
		T2.add(1,1,n,1,sa[i],n-sa[i]+1);
		s=(s+1ll*sa[i]*(n-sa[i]+1))%MOD;
		ans+=(s-T1.query(1,1,n,1,sa[i]-1)-T2.query(1,1,n,sa[i]+1,n)+MOD+MOD)*a[sa[i]]%MOD;
	}
	ans%=MOD;
	printf("%I64d\n",ans);
	return 0;
}