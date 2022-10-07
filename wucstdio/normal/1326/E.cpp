#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid (l+r)/2
using namespace std;
int n,p[300005],q[300005],sa[300005];
struct Tree
{
	struct Node
	{
		int addv;
		int minx;
	}tree[1200005];
	void pushup(int x)
	{
		tree[x].minx=min(tree[lc].minx,tree[rc].minx);
	}
	void pushdown(int x)
	{
		if(tree[x].addv)
		{
			tree[lc].addv+=tree[x].addv;
			tree[rc].addv+=tree[x].addv;
			tree[lc].minx+=tree[x].addv;
			tree[rc].minx+=tree[x].addv;
			tree[x].addv=0;
		}
	}
	void add(int x,int l,int r,int from,int to,int v)
	{
		if(l>=from&&r<=to)
		{
			tree[x].addv+=v;
			tree[x].minx+=v;
			return;
		}
		pushdown(x);
		if(from<=mid)add(lc,l,mid,from,to,v);
		if(to>mid)add(rc,mid+1,r,from,to,v);
		pushup(x);
	}
	int ask(int x,int l,int r,int from,int to)
	{
		if(to<1)return 0;
		if(l>=from&&r<=to)return tree[x].minx;
		pushdown(x);
		int ans=2147483647;
		if(from<=mid)ans=min(ans,ask(lc,l,mid,from,to));
		if(to>mid)ans=min(ans,ask(rc,mid+1,r,from,to));
		return ans;
	}
}T;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		sa[p[i]]=i;
	}
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	printf("%d ",n);
	int ans=n;
	for(int i=1;i<n;i++)
	{
		T.add(1,1,n,q[i],n,-1);
		while(T.ask(1,1,n,sa[ans],n)<min(0,T.ask(1,1,n,1,sa[ans]-1)))
		{
			T.add(1,1,n,sa[ans],n,1);
			ans--;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}