#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int minv;
	int setv;
}tree[800005];
int n,m,a[200005];
void pushup(int o)
{
	tree[o].minv=min(tree[lson].minv,tree[rson].minv);
}
void pushdown(int o)
{
	if(tree[o].setv)
	{
		tree[lson].minv=max(tree[lson].minv,tree[o].setv);
		tree[rson].minv=max(tree[rson].minv,tree[o].setv);
		tree[lson].setv=max(tree[lson].setv,tree[o].setv);
		tree[rson].setv=max(tree[rson].setv,tree[o].setv);
		tree[o].setv=0;
	}
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].minv=a[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int p,int v)
{
	if(l==r)
	{
		tree[o].minv=v;
		return;
	}
	pushdown(o);
	if(p<=mid)update(lson,l,mid,p,v);
	else update(rson,mid+1,r,p,v);
	pushup(o);
}
void setv(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].setv=max(tree[o].setv,v);
		tree[o].minv=max(tree[o].minv,v);
		return;
	}
	pushdown(o);
	if(from<=mid)setv(lson,l,mid,from,to,v);
	if(to>mid)setv(rson,mid+1,r,from,to,v);
	pushup(o);
}
int ask(int o,int l,int r,int p)
{
	if(l==r)return tree[o].minv;
	pushdown(o);
	if(p<=mid)return ask(lson,l,mid,p);
	else return ask(rson,mid+1,r,p);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			scanf("%d",&y);
			update(1,1,n,x,y);
		}
		else setv(1,1,n,1,n,x);
	}
	for(int i=1;i<=n;i++)printf("%d ",ask(1,1,n,i));
	printf("\n");
	return 0;
}