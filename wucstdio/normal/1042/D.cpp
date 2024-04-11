#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define root tree[0].child[1]
using namespace std;
const ll INF=214748364700000000;
struct Splay
{
	int num;
	int sum;
	int child[2];
	int parent;
	ll value;
}tree[400005];
int n,m,points;
bool identify(int o)
{
	return tree[tree[o].parent].child[1]==o;
}
void connect(int o,int pa,bool flag)
{
	tree[o].parent=pa;
	tree[pa].child[flag]=o;
}
void update(int o)
{
	tree[o].sum=tree[lson].sum+tree[rson].sum+tree[o].num;
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
void splay(int at,int to)
{
	to=tree[to].parent;
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
int crepoint(ll v,int pa)
{
	tree[++n].value=v;
	tree[n].parent=pa;
	tree[n].sum=tree[n].num=1;
	return n;
}
void destroy(int o)
{
	tree[o].child[0]=tree[o].child[1]=tree[o].parent=0;
	tree[o].num=tree[o].sum=tree[o].value=0;
	if(o==n)n--;
}
int build(ll v)
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
		tree[o].sum++;
		if(tree[o].value==v)
		{
			tree[o].num++;
			return o;
		}
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
void push(ll v)
{
	int add=build(v);
	splay(add,root);
}
int find(ll v)
{
	int o=root;
	while(o)
	{
		if(tree[o].value==v)
		{
			splay(o,root);
			return o;
		}
		o=tree[o].child[v>tree[o].value];
	}
	return 0;
}
void pop(ll v)
{
	int o=find(v);
	if(!o)return;
	points--;
	if(tree[o].num>1)
	{
		tree[o].num--;
		tree[o].sum--;
		return;
	}
	if(!lson)
	{
		root=rson;
		tree[root].parent=0;
		destroy(o);
	}
	else if(!rson)
	{
		root=lson;
		tree[root].parent=0;
		destroy(o);
	}
	else
	{
		int node=lson;
		while(tree[node].child[1])node=tree[node].child[1];
		splay(node,lson);
		connect(rson,lson,1);
		update(lson);
		root=lson;
		tree[root].parent=0;
		destroy(o);
	}
}
ll N,sum[200005],ans,t;
int main()
{
	scanf("%I64d%I64d",&N,&t);
	for(int i=1;i<=N;i++)
	{
		scanf("%I64d",&sum[i]);
		sum[i]+=sum[i-1];
	}
//	for(int i=1;i<=N;i++)printf("%I64d ",sum[i]);
//	printf("\n");
	push(sum[N]);
	for(int i=N-1;i>=0;i--)
	{
		push(sum[i]+t);
		ans+=tree[tree[root].child[0]].sum;
		pop(sum[i]+t);
		push(sum[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}