#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
const ll MOD=998244353;
struct Tree
{
	ll sum;
	ll mul;
	ll add;
}tree[800005];
int n,m,a[200005];
void pushup(int o)
{
	tree[o].sum=tree[lson].sum+tree[rson].sum;
	if(tree[o].sum>=MOD)tree[o].sum-=MOD;
}
void pushdown(int o,int l,int r)
{
	if(tree[o].mul!=1)
	{
		tree[lson].mul*=tree[o].mul;
		tree[rson].mul*=tree[o].mul;
		tree[lson].sum*=tree[o].mul;
		tree[rson].sum*=tree[o].mul;
		tree[lson].add*=tree[o].mul;
		tree[rson].add*=tree[o].mul;
		if(tree[o].mul==-1)
		{
			tree[lson].sum+=MOD;
			tree[rson].sum+=MOD;
			tree[lson].add+=MOD;
			tree[rson].add+=MOD;
		}
		tree[o].mul=1;
	}
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
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].sum=1;
		tree[o].mul=1;
		tree[o].add=0;
		return;
	}
	tree[o].mul=1;
	tree[o].add=0;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
	return;
}
void add(int o,int l,int r,int from,int to,ll v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[o].add+=v;
		tree[o].sum=(tree[o].sum+(r-l+1)*v)%MOD;
		if(tree[o].add>=MOD)tree[o].add-=MOD;
		return;
	}
	pushdown(o,l,r);
	if(from<=mid)add(lson,l,mid,from,to,v);
	if(to>mid)add(rson,mid+1,r,from,to,v);
	pushup(o);
}
void mul(int o,int l,int r,int from,int to,int v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[o].add*=v;
		tree[o].sum*=v;
		tree[o].mul*=v;
		if(v==-1)
		{
			tree[o].add+=MOD;
			tree[o].sum+=MOD;
		}
		return;
	}
	pushdown(o,l,r);
	if(from<=mid)mul(lson,l,mid,from,to,v);
	if(to>mid)mul(rson,mid+1,r,from,to,v);
	pushup(o);
}
ll query(int o,int l,int r,int from,int to)
{
	if(from>to)return 0;
	if(l>=from&&r<=to)return tree[o].sum;
	ll ans=0;
	if(from<=mid)ans+=query(lson,l,mid,from,to);
	if(to>mid)ans+=query(rson,mid+1,r,from,to);
	if(ans>=MOD)ans-=MOD;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,m);
	if(a[1]!=-1)
	{
		mul(1,1,m,1,a[1]-1,0);
		mul(1,1,m,a[1]+1,m,0);
	}
	for(int i=3;i<=n;i+=2)
	{
		ll s=query(1,1,m,1,m);
		mul(1,1,m,1,m,-1);
		add(1,1,m,1,m,s);
		if(a[i]!=-1)
		{
			mul(1,1,m,1,a[i]-1,0);
			mul(1,1,m,a[i]+1,m,0);
		}
	}
	ll ans=query(1,1,m,1,m);
	build(1,1,m);
	if(a[2]!=-1)
	{
		mul(1,1,m,1,a[2]-1,0);
		mul(1,1,m,a[2]+1,m,0);
	}
	for(int i=4;i<=n;i+=2)
	{
		ll s=query(1,1,m,1,m);
		mul(1,1,m,1,m,-1);
		add(1,1,m,1,m,s);
		if(a[i]!=-1)
		{
			mul(1,1,m,1,a[i]-1,0);
			mul(1,1,m,a[i]+1,m,0);
		}
	}
	ans=ans*query(1,1,m,1,m)%MOD;
	printf("%I64d\n",ans);
	return 0;
}