#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int child[2];
	int val;
}tree[15000005];
int q,n,last[500005],a[500005],root[500005],tot;
ll g[500005],ans;
void update(int pre,int o,int l,int r,int p,int v)
{
	if(l==r)
	{
		tree[o].val=v;
		return;
	}
	if(p<=mid)
	{
		lson=++tot;
		tree[lson]=tree[tree[pre].child[0]];
		update(tree[pre].child[0],lson,l,mid,p,v);
	}
	else
	{
		rson=++tot;
		tree[rson]=tree[tree[pre].child[1]];
		update(tree[pre].child[1],rson,mid+1,r,p,v);
	}
}
int ask(int o,int l,int r,int p)
{
	if(l==r)return tree[o].val;
	if(p<=mid)return ask(lson,l,mid,p);
	else return ask(rson,mid+1,r,p);
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		tot=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			last[i]=ask(root[i-1],1,n,a[i]);
			if(last[i])g[i]=g[last[i]-1]+1;
			else g[i]=0;
			last[i]--;
			root[i]=++tot;
			tree[root[i]]=tree[root[last[i]]];
			update(root[last[i]],root[i],1,n,a[i],i);
			ans+=g[i];
		}
		printf("%lld\n",ans);
		for(int i=1;i<=tot;i++)tree[i].child[0]=tree[i].child[1]=tree[i].val=0;
	}
	return 0;
}