#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
const ll MOD=998244353;
struct Tree
{
	ll prod;
	ll val;
	int st,en;
}tree[800005];
int n,q;
ll res;
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
void pushup(int o)
{
	tree[o].prod=tree[lson].prod*tree[rson].prod%MOD;
	tree[o].val=(tree[lson].val+tree[lson].prod*tree[rson].val)%MOD;
	tree[o].st=min(tree[lson].st,tree[rson].st);
	tree[o].en=max(tree[rson].en,tree[lson].en);
}
void build(int o,int l,int r,int p,ll v)
{
	if(l==r)
	{
		tree[o].val=tree[o].prod=v;
		return;
	}
	if(p<=mid)build(lson,l,mid,p,v);
	else build(rson,mid+1,r,p,v);
	pushup(o);
}
ll ans,T;
void calc(int o,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)
	{
		ans=(ans+T*tree[o].val)%MOD;
		T=T*tree[o].prod%MOD;
		return;
	}
	if(from<=mid)calc(lson,l,mid,from,to);
	if(to>mid)calc(rson,mid+1,r,from,to);
}
ll ask(int l,int r)
{
	ans=0,T=1;
	calc(1,1,n,l,r);
	ans++;
	return (ans*quick_pow(T,MOD-2)-1+MOD)%MOD;
}
int upper(int o,int l,int r,int p)
{
	if(tree[o].st>p)return tree[o].st;
	if(tree[lson].en>p)return upper(lson,l,mid,p);
	return upper(rson,mid+1,r,p);
}
int lower(int o,int l,int r,int p)
{
	if(tree[o].en<p)return tree[o].en;
	if(tree[rson].st<p)return lower(rson,mid+1,r,p);
	return lower(lson,l,mid,p);
}
void rev(int o,int l,int r,int p)
{
	if(l==r)
	{
		int st=lower(1,1,n,p);
		int en=upper(1,1,n,p);
		ll v1=ask(st,en-1);
		ll v2=(ask(st,p-1)+ask(p,en-1))%MOD;
		if(tree[o].st==l)tree[o].st=n+1,tree[o].en=1,res=(res+v1-v2+MOD)%MOD;
		else tree[o].st=tree[o].en=l,res=(res+v2-v1+MOD)%MOD;
		return;
	}
	if(p<=mid)rev(lson,l,mid,p);
	if(p>mid)rev(rson,mid+1,r,p);
	pushup(o);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=4*n;i++)tree[i].st=n+1,tree[i].en=1;
	ll inv=quick_pow(100,MOD-2);
	for(int i=1;i<=n;i++)
	{
		ll p;
		scanf("%lld",&p);
		p=p*inv%MOD;
		build(1,1,n,i,p);
	}
	res=ask(1,n);
	printf("%lld\n",res);
	return 0;
}