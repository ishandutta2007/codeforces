#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
struct Tree
{
	ll minv;
	ll addv;
}tree[800005];
int n,m,p[200005];
ll s[200005];
void pushup(int o)
{
	tree[o].minv=min(tree[lson].minv,tree[rson].minv);
}
void pushdown(int o)
{
	if(tree[o].addv)
	{
		tree[lson].addv+=tree[o].addv;
		tree[rson].addv+=tree[o].addv;
		tree[lson].minv+=tree[o].addv;
		tree[rson].minv+=tree[o].addv;
		tree[o].addv=0;
	}
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].minv=s[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
void add(int o,int l,int r,int from,int to,int v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[o].addv+=v;
		tree[o].minv+=v;
		return;
	}
	pushdown(o);
	if(from<=mid)add(lson,l,mid,from,to,v);
	if(to>mid)add(rson,mid+1,r,from,to,v);
	pushup(o);
}
int ask(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].minv=1e18;
		return l;
	}
	pushdown(o);
	int ans=0;
	if(tree[rson].minv==0)ans=ask(rson,mid+1,r);
	else ans=ask(lson,l,mid);
	pushup(o);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int x=ask(1,1,n);
		p[x]=i;
		add(1,1,n,x+1,n,-i);
	}
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	printf("\n");
	return 0;
}