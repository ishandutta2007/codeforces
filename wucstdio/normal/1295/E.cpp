#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	ll s0,s1;
	ll ans;
}tree[800005];
int n,p[200005],pos[200005];
ll a[200005];
void pushup(int o)
{
	tree[o].s0=tree[lson].s0+tree[rson].s0;
	tree[o].s1=tree[lson].s1+tree[rson].s1;
	tree[o].ans=min(tree[lson].ans+tree[rson].s0,tree[rson].ans+tree[lson].s1);
	tree[o].ans=min(tree[o].ans,tree[lson].s1+tree[rson].s0);
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].s1=a[l];
		tree[o].ans=1e18;
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int p)
{
	if(l==r)
	{
		tree[o].s0=tree[o].s1;
		tree[o].s1=0;
		return;
	}
	if(p<=mid)update(lson,l,mid,p);
	else update(rson,mid+1,r,p);
	pushup(o);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	ll ans=tree[1].ans;
	for(int i=1;i<=n;i++)
	{
		update(1,1,n,pos[i]);
		ans=min(ans,tree[1].ans);
	}
	printf("%lld\n",ans);
	return 0;
}