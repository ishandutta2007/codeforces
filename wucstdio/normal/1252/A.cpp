#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define rand() (rand()*32768+rand())
using namespace std;
int n,root;
ll sum,ans;
struct Treap
{
	#define lc tree[x].child[0]
	#define rc tree[x].child[1]
	struct Node
	{
		int child[2];
		ll val,add;
		int size;
		int key;
	}tree[100005];
	int tot;
	void pushup(int x)
	{
		tree[x].size=tree[lc].size+tree[rc].size+1;
	}
	void pushdown(int x)
	{
		if(tree[x].add)
		{
			tree[lc].add+=tree[x].add;
			tree[rc].add+=tree[x].add;
			tree[lc].val+=tree[x].add;
			tree[rc].val+=tree[x].add;
			tree[x].add=0;
		}
	}
	void rotate(int&x,int d)
	{
		int y=tree[x].child[d];
		pushdown(x),pushdown(y);
		tree[x].child[d]=tree[y].child[!d];
		tree[y].child[!d]=x;
		pushup(x),pushup(y);
		x=y;
	}
	void ins(int&x,int l,int r,ll v)
	{
		if(!x)
		{
			x=++tot;
			tree[x].val=v*(r+1);
			tree[x].key=rand();
			tree[x].size=1;
			return;
		}
		pushdown(x);
		int mid=l+tree[lc].size;
		int d=mid*v<tree[x].val;
		if(d)ins(rc,mid+1,r,v);
		else
		{
			ins(lc,l,mid-1,v);
			tree[x].val+=v;
			if(rc)tree[rc].val+=v,tree[rc].add+=v;
		}
		pushup(x);
		if(tree[tree[x].child[d]].key<tree[x].key)rotate(x,d);
	}
	void ask(int x,int l,int r)
	{
		pushdown(x);
		int mid=l+tree[lc].size;
		if(lc)ask(lc,l,mid-1);
		sum+=tree[x].val,ans=max(ans,sum);
		if(rc)ask(rc,mid+1,r);
	}
	#undef lc
	#undef rc
}T;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll v;
		scanf("%lld",&v);
		T.ins(root,1,i-1,v);
	}
	T.ask(root,1,n);
	printf("%lld\n",ans);
	return 0;
}