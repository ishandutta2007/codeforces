#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Treap
{
	#define lson tree[o].child[0]
	#define rson tree[o].child[1]
	const int INF=2147483647;
	struct Node
	{
		int child[2];
		int val,key;
		int size;
	}tree[500005];
	int root,tot=0,n;
	void update(int o)
	{
		tree[o].size=tree[lson].size+tree[rson].size+1;
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
	int find(int k)
	{
		if(k>tree[root].size)return INF;
		int o=root;
		while(o)
		{
			if(tree[lson].size==k-1)return tree[o].val;
			if(tree[lson].size>=k)o=lson;
			else k-=tree[lson].size+1,o=rson;
		}
		return 0;
	}
	void insert(int v)
	{
		pair<int,int>x=split(root,v);
		tree[++tot].size=1,tree[tot].val=v,tree[tot].key=rand();
		root=merge(merge(x.first,tot),x.second);
	}
}S;
struct Query
{
	ll k;
	int id;
}a[500005];
int n,m,q,sa[500005],ans[500005];
ll num[500005];
bool cmp(int a,int b)
{
	return num[a]<num[b]||(num[a]==num[b]&&a<b);
}
bool cmp1(Query x,Query y)
{
	return x.k<y.k;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	for(int i=1;i<=m;i++)sa[i]=i;
	sort(sa+1,sa+m+1,cmp);
	sa[m+1]=m+1;
	num[m+1]=1e18;
	for(int i=1;i<=q;i++)
	{
		scanf("%I64d",&a[i].k);
		a[i].k-=n;
		a[i].id=i;
	}
	sort(a+1,a+q+1,cmp1);
	int now=1;
	ll tot=0;
	S.insert(sa[1]);
	for(int i=1;i<=q;i++)
	{
		while(num[sa[now]]==num[sa[now+1]])
		{
			now++;
			S.insert(sa[now]);
		}
		while(tot<a[i].k)
		{
			if(now==m)break;
			if(tot+1ll*(num[sa[now+1]]-num[sa[now]])*now>=a[i].k)break;
			else
			{
				tot+=1ll*(num[sa[now+1]]-num[sa[now]])*now;
				now++;
				S.insert(sa[now]);
			}
		}
		ll rest=(a[i].k-tot-1)%now+1;
		ans[a[i].id]=S.find(rest);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}