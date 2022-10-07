#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define root tree[0].child[1]
#define ll long long
using namespace std;
const int INF=2147483647;
const ll MOD=998244353;
struct Splay
{
	int sum;
	int parent;
	int child[2];
	int value;
	int tag;
}tree[400005];
int n,m,points;
void update(int o)
{
	tree[o].sum=tree[lson].sum+tree[rson].sum+1;
}
void pushdown(int o)
{
	if(!tree[o].tag)return;
	if(lson)tree[lson].value+=tree[o].tag,tree[lson].tag+=tree[o].tag;
	if(rson)tree[rson].value+=tree[o].tag,tree[rson].tag+=tree[o].tag;
	tree[o].tag=0;
}
bool identify(int o)
{
	return tree[tree[o].parent].child[1]==o;
}
void connect(int o,int pa,bool flag)
{
	tree[o].parent=pa;
	tree[pa].child[flag]=o;
}
void rotate(int x)
{
	int y=tree[x].parent;
	int r=tree[y].parent;
	bool flag_x=identify(x);
	bool flag_y=identify(y);
	int b=tree[x].child[!flag_x];
	connect(b,y,flag_x);
	connect(y,x,!flag_x);
	connect(x,r,flag_y);
	update(y);
	update(x);
}
int st[400005],top;
void splay(int at,int to)
{
	to=tree[to].parent;
	int tmp=at;
	while(tmp!=to)st[++top]=tmp,tmp=tree[tmp].parent;
	while(top)pushdown(st[top--]);
	while(tree[at].parent!=to)
	{
		int pa=tree[at].parent;
		if(tree[pa].parent==to)rotate(at);
		else if(identify(at)==identify(pa))
		{
			rotate(pa);
			rotate(at);
		}
		else
		{
			rotate(at);
			rotate(at);
		}
	}
}
int find(int v)
{
	int o=root;
	while(o)
	{
		pushdown(o);
		if(tree[o].value==v)
		{
			splay(o,root);
			return o;
		}
		o=tree[o].child[v>tree[o].value];
	}
	return 0;
}
int crepoint(int v,int pa)
{
	tree[++n].value=v;
	tree[n].sum=1;
	tree[n].parent=pa;
	tree[n].child[0]=tree[n].child[1]=0;
	tree[n].tag=0;
	return n;
}
void destroy(int o)
{
	tree[o].sum=tree[o].value=0;
	tree[o].parent=tree[o].child[0]=tree[o].child[1]=0;
}
int build(int v)
{
	int o=root;
	points++;
	if(!o)
	{
		root=crepoint(v,0);
		return root;
	}
	while(1)
	{
		pushdown(o);
		tree[o].sum++;
		bool next=v>tree[o].value;
		if(!tree[o].child[next])
		{
			tree[o].child[next]=crepoint(v,o);
			return tree[o].child[next];
		}
		o=tree[o].child[next];
	}
	return 0;
}
void push(int v)
{
	int add=build(v);
	splay(add,root);
}
void pop(int v)
{
	int o=find(v);
	if(!o)return;
	pushdown(o);
	points--;
	if(!lson)
	{
		connect(rson,0,1);
		destroy(o);
		return;
	}
	if(!rson)
	{
		connect(lson,0,1);
		destroy(o);
		return;
	}
	int node=lson;
	while(tree[node].child[1])pushdown(node),node=tree[node].child[1];
	splay(node,lson);
	connect(rson,lson,1);
	update(lson);
	connect(lson,0,1);
	destroy(o);
}
int t,nn,mm;
ll fact[400005],inv[400005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<=400000;i++)fact[i]=fact[i-1]*i%MOD;
	inv[400000]=quick_pow(fact[400000],MOD-2);
	for(int i=400000;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	scanf("%d",&t);
	while(t--)
	{
		points=root=n=0;
		scanf("%d%d",&nn,&mm);
		while(mm--)
		{
			int xx,y;
			scanf("%d%d",&xx,&y);
			pop(y-1);
			push(y-1);
			int o=tree[root].child[1];
			tree[o].tag++,tree[o].value++;
			pop(y-1);
			push(y);
		}
		int num=tree[root].sum+1;
		int k=nn+(nn+1-num);
		printf("%lld\n",fact[k-1]*inv[nn]%MOD*inv[k-nn-1]%MOD);
	}
	return 0;
}