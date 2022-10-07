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
	ll minv;
	ll setv;
	ll addv;
	int now;
}tree[400005];
int n,q;
ll t[100005],p[15];
void pushup(int o)
{
	tree[o].minv=min(tree[lson].minv,tree[rson].minv);
}
void pushdown(int o)
{
	if(tree[o].setv)
	{
		tree[lson].setv=tree[o].setv;
		tree[rson].setv=tree[o].setv;
		tree[lson].minv=tree[o].minv;
		tree[rson].minv=tree[o].minv;
		tree[lson].addv=0;
		tree[rson].addv=0;
		tree[lson].now=tree[o].now;
		tree[rson].now=tree[o].now;
		tree[o].setv=0;
		tree[o].now=0;
	}
	if(tree[o].addv)
	{
		tree[lson].addv+=tree[o].addv;
		tree[rson].addv+=tree[o].addv;
		tree[lson].minv-=tree[o].addv;
		tree[rson].minv-=tree[o].addv;
		tree[o].addv=0;
	}
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		int now=0;
		while(p[now]<t[l])now++;
		tree[o].setv=t[l];
		tree[o].minv=p[now]-t[l];
		tree[o].now=now;
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
ll ask(int o,int l,int r,int p)
{
	if(tree[o].setv)return tree[o].setv+tree[o].addv;
	pushdown(o);
	if(p<=mid)return ask(lson,l,mid,p);
	else return ask(rson,mid+1,r,p);
}
bool add(int o,int l,int r,int from,int to,ll v)
{
	if(l>=from&&r<=to)
	{
		if(tree[o].minv>v)
		{
			tree[o].minv-=v;
			tree[o].addv+=v;
			return 0;
		}
		if(tree[o].minv<=v)
		{
			if(tree[o].setv)
			{
				tree[o].setv+=tree[o].addv;
				tree[o].setv+=v;
				tree[o].addv=0;
				int now=tree[o].now;
				while(p[now]<tree[o].setv)now++;
				tree[o].minv=p[now]-tree[o].setv;
				tree[o].now=now;
				if(tree[o].minv==0)return 1;
				else return 0;
			}
			bool ans=0;
			pushdown(o);
			ans|=add(lson,l,mid,from,to,v);
			ans|=add(rson,mid+1,r,from,to,v);
			pushup(o);
			return ans;
		}
	}
	pushdown(o);
	bool ans=0;
	if(from<=mid)ans|=add(lson,l,mid,from,to,v);
	if(to>mid)ans|=add(rson,mid+1,r,from,to,v);
	pushup(o);
	return ans;
}
void set(int o,int l,int r,int from,int to,ll v)
{
	if(l>=from&&r<=to)
	{
		tree[o].setv=v;
		tree[o].addv=0;
		int now=0;
		while(p[now]<tree[o].setv)now++;
		tree[o].minv=p[now]-tree[o].setv;
		tree[o].now=now;
		return;
	}
	pushdown(o);
	if(from<=mid)set(lson,l,mid,from,to,v);
	if(to>mid)set(rson,mid+1,r,from,to,v);
	pushup(o);
}
int main()
{
	p[0]=1;
	for(int i=1;i<12;i++)p[i]=p[i-1]*42;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	build(1,1,n);
	while(q--)
	{
		int type,l,r,x;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&x);
			printf("%lld\n",ask(1,1,n,x));
		}
		if(type==2)
		{
			scanf("%d%d%d",&l,&r,&x);
			set(1,1,n,l,r,x);
		}
		if(type==3)
		{
			scanf("%d%d%d",&l,&r,&x);
			while(add(1,1,n,l,r,x));
		}
	}
	return 0;
}