#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define mid (l+r)/2
using namespace std;
struct Treap
{
	int child[2];
	int size;
	int val,key;
}tree[5000005];
int n,m,a[200005],root[200005],tot;
ll ans;
void pushup(int o)
{
	tree[o].size=tree[lson].size+tree[rson].size+1;
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(tree[x].key<tree[y].key)
	{
		tree[x].child[1]=merge(tree[x].child[1],y);
		pushup(x);
		return x;
	}
	else
	{
		tree[y].child[0]=merge(x,tree[y].child[0]);
		pushup(y);
		return y;
	}
}
pair<int,int>split(int o,int v)
{
	if(!o)return make_pair(0,0);
	pair<int,int>x;
	if(tree[o].val>v)
	{
		x=split(lson,v);
		lson=x.second;
		pushup(o);
		x.second=o;
	}
	else
	{
		x=split(rson,v);
		rson=x.first;
		pushup(o);
		x.first=o;
	}
	return x;
}
void _ins(int t,int val)
{
	pair<int,int>x=split(root[t],val-1);
	tree[++tot].val=val,tree[tot].size=1,tree[tot].key=rand();
	root[t]=merge(merge(x.first,tot),x.second);
}
void _del(int t,int v)
{
	pair<int,int>x=split(root[t],v-1),y=split(x.second,v);
	root[t]=merge(x.first,y.second);
}
int _calc(int t,int v)
{
	pair<int,int>x=split(root[t],v-1);
	int ans=tree[x.first].size;
	root[t]=merge(x.first,x.second);
	return ans;
}
ll calc(int p,int x)
{
	ll ans=0;
	int now=n;
	while(now)
	{
		ans+=_calc(now,x);
		now&=now-1;
	}
	now=p;
	while(now)
	{
		ll y=_calc(now,x);
		ans-=y;
		ans+=tree[root[now]].size-y;
		now&=now-1;
	}
	return ans;
}
ll ins(int p,int x)
{
	ll ans=calc(p,x);
	while(p<=n)
	{
		_ins(p,x);
		p+=p^(p&(p-1));
	}
	return ans;
}
ll del(int p,int x)
{
	int now=p;
	while(p<=n)
	{
		_del(p,x);
		p+=p^(p&(p-1));
	}
	return calc(now,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
		ans+=ins(i,a[i]);
	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x!=y)
		{
			ans-=del(x,a[x]);
			ans-=del(y,a[y]);
			swap(a[x],a[y]);
			ans+=ins(x,a[x]);
			ans+=ins(y,a[y]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}