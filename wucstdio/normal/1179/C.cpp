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
	int addv;
}tree[4000005];
int n,m,q,a[300005],b[300005],cnt[1000005];
void pushup(int o)
{
	tree[o].minv=min(tree[lson].minv,tree[rson].minv);
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].minv=1000000000;
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
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
void add(int o,int l,int r,int from,int to,int v)
{
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
	if(tree[o].minv>=0)return -1;
	if(l==r)return l;
	pushdown(o);
	if(tree[rson].minv<0)return ask(rson,mid+1,r);
	else return ask(lson,l,mid);
}
void debug(int o,int l,int r)
{
	if(l>10)return;
	if(l==r)
	{
		printf("%d ",tree[o].minv);
		return;
	}
	pushdown(o);
	debug(lson,l,mid);
	debug(rson,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,1000000);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(cnt[a[i]]==1)add(1,1,1000000,a[i],a[i],-1000000000);
		add(1,1,1000000,1,a[i],-1);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		add(1,1,1000000,1,b[i],1);
	}
	scanf("%d",&q);
	while(q--)
	{
		int opt,i,x;
		scanf("%d%d%d",&opt,&i,&x);
		if(opt==1)
		{
			add(1,1,1000000,1,a[i],1);
			cnt[a[i]]--;
			if(cnt[a[i]]==0)add(1,1,1000000,a[i],a[i],1000000000);
			a[i]=x;
			add(1,1,1000000,1,a[i],-1);
			cnt[a[i]]++;
			if(cnt[a[i]]==1)add(1,1,1000000,a[i],a[i],-1000000000);
		}
		else
		{
			add(1,1,1000000,1,b[i],-1);
			b[i]=x;
			add(1,1,1000000,1,b[i],1);
		}
		printf("%d\n",ask(1,1,1000000));
	}
	return 0;
}