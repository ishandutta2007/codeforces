#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson tree[o].child[0]
#define rson tree[o].child[1]
using namespace std;
const int INF=2147483647;
struct Treap
{
	int child[2];
	int val,key;
	int size,sum;
}tree[200005];
int root,tot=0,n,m;
void update(int o)
{
	tree[o].size=tree[lson].size+tree[rson].size+1;
	tree[o].sum=tree[lson].sum+tree[rson].sum+tree[o].val;
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(tree[x].key<tree[y].key)
	{
		tree[x].child[1]=merge(tree[x].child[1],y);
		update(x);
		return x;
	}
	else
	{
		tree[y].child[0]=merge(x,tree[y].child[0]);
		update(y);
		return y;
	}
}
pair<int,int>split(int o,int v)
{
	if(!o)return make_pair(0,0);
	pair<int,int>y;
	if(tree[o].val>v)
	{
		y=split(lson,v);
		lson=y.second;
		update(o);
		y.second=o;
	}
	else
	{
		y=split(rson,v);
		rson=y.first;
		update(o);
		y.first=o;
	}
	return y;
}
void insert(int v)
{
	pair<int,int>x=split(root,v);
	tree[++tot].size=1,tree[tot].val=v,tree[tot].key=rand(),tree[tot].sum=v;
	root=merge(merge(x.first,tot),x.second);
}
void del(int v)
{
	pair<int,int>x=split(root,v-1),y=split(x.second,v);
	root=merge(merge(x.first,tree[y.first].child[0]),merge(tree[y.first].child[1],y.second));
}
int ask(int o,int s)
{
	if(!o)return 0;
	if(tree[o].sum<=s)return tree[o].size;
	if(tree[lson].sum+tree[o].val<=s)return tree[lson].size+1+ask(rson,s-tree[lson].sum-tree[o].val);
	if(tree[lson].sum<=s)return tree[lson].size;
	return ask(lson,s);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		printf("%d ",i-1-ask(root,m-v));
		insert(v);
	}
	printf("\n");
	return 0;
}