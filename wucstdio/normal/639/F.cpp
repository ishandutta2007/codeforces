#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define mid (l+r)/2
#define rand() (rand()*32768+rand())
using namespace std;
struct Tree
{
	int child[2];
	int parent;
	bool rev;
	bool setv;
	int sum;
	int size;
	int val;
}tree[600005],_tree[600005];
int n,m,q,x[300005],tot,_tot;
int s[600005],num;
bool flag[600005];
void vis(int o)
{
	if(!flag[o])
	{
		flag[o]=1;
		s[++num]=o;
	}
}
bool nroot(int o)
{
	return tree[tree[o].parent].child[0]==o||tree[tree[o].parent].child[1]==o;
}
void pushup(int o)
{
	tree[o].sum=tree[lson].sum+tree[rson].sum+tree[o].val;
	tree[o].size=tree[lson].size+tree[rson].size+(o>n);
}
void pushr(int o)
{
	swap(lson,rson);
	tree[o].rev^=1;
}
void pushdown(int o)
{
	vis(o);
	vis(lson),vis(rson);
	if(tree[o].rev)
	{
		pushr(lson);
		pushr(rson);
		tree[o].rev=0;
	}
	if(tree[o].setv)
	{
		tree[lson].setv=1;
		tree[rson].setv=1;
		tree[lson].sum=tree[lson].size;
		tree[rson].sum=tree[rson].size;
		if(lson>n)tree[lson].val=1;
		if(rson>n)tree[rson].val=1;
		tree[o].setv=0;
	}
}
bool identify(int o)
{
	return tree[tree[o].parent].child[1]==o;
}
void rotate(int x)
{
	int y=tree[x].parent;
	int r=tree[y].parent;
	bool flag_x=identify(x);
	bool flag_y=identify(y);
	int b=tree[x].child[!flag_x];
	if(nroot(y))tree[r].child[flag_y]=x;
	tree[x].child[!flag_x]=y;
	tree[y].child[flag_x]=b;
	tree[b].parent=y;
	tree[y].parent=x;
	tree[x].parent=r;
	pushup(y);
	pushup(x);
	vis(x);
	vis(y);
	vis(r);
	vis(b);
}
int st[300005],top;
void splay(int at)
{
	int node=at;
	while(nroot(node))
	{
		st[++top]=node;
		node=tree[node].parent;
	}
	st[++top]=node;
	while(top)pushdown(st[top--]);
	while(nroot(at))
	{
		int pa=tree[at].parent;
		if(!nroot(pa))rotate(at);
		else if(identify(pa)==identify(at))
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
void access(int o)
{
	int last=0;
	while(o)
	{
		splay(o);
		rson=last;
		pushup(o);
		last=o;
		o=tree[o].parent;
	}
}
void makeroot(int o)
{
	access(o);
	splay(o);
	pushr(o);
}
int findroot(int o)
{
	access(o);
	splay(o);
	while(lson)
	{
		pushdown(o);
		o=lson;
	}
	return o;
}
void split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x,int y)
{
	makeroot(x);
	if(findroot(y)==x)return;
	tree[x].parent=y;
}
void setv(int x,int y)
{
	split(x,y);
	tree[y].sum=tree[y].size;
	tree[y].setv=1;
	if(y>n)tree[y].val=1;
}
int ask(int x,int y)
{
	split(x,y);
	return findroot(y)==x&&tree[y].sum==tree[y].size;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=n+1;i<=2*n;i++)tree[i].size=1;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		makeroot(u);
		if(findroot(v)!=u)
		{
			int x=++tot;
			link(x,u);
			link(x,v);
		}
		else setv(u,v);
	}
	for(int i=1;i<=2*n;i++)_tree[i]=tree[i];
	_tot=tot;
	int lastans=0;
	for(int o=1;o<=q;o++)
	{
		tot=_tot;
		int ni,mi;
		scanf("%d%d",&ni,&mi);
		for(int i=1;i<=ni;i++)
		{
			scanf("%d",&x[i]);
			x[i]=(x[i]+lastans-1)%n+1;
		}
		for(int i=1;i<=mi;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u=(u+lastans-1)%n+1;
			v=(v+lastans-1)%n+1;
			makeroot(u);
			if(findroot(v)!=u)
			{
				int x=++tot;
				link(x,u);
				link(x,v);
			}
			else setv(u,v);
		}
		bool ff=1;
		for(int i=2;i<=ni;i++)
		{
			if(!ask(x[i],x[i-1]))
			  ff=0;
		}
		lastans+=ff*o;
		if(ff)printf("YES\n");
		else printf("NO\n");
		lastans%=n;
		while(num)
		{
			flag[s[num]]=0;
			tree[s[num]]=_tree[s[num]];
			num--;
		}
	}
	return 0;
}