#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define lson tree[x].child[0]
#define rson tree[x].child[1]
using namespace std;
struct Tree
{
	int child[2];
	int parent;
	int size;
	int tot;
	int val;
	int maxv;
	int node;
	bool rev;
}tree[1000005];
struct Edge
{
	int from,to;
	int len;
}e[300005];
int n,m,nowans,num;
priority_queue<pair<int,int> >q,del;
bool nroot(int x)
{
	return tree[tree[x].parent].child[0]==x||tree[tree[x].parent].child[1]==x;
}
bool identify(int x)
{
	return tree[tree[x].parent].child[1]==x;
}
void pushup(int x)
{
	tree[x].size=tree[lson].size+tree[lson].tot+tree[rson].size+tree[rson].tot+(x<=n);
	tree[x].maxv=max(tree[lson].maxv,tree[rson].maxv);
	tree[x].maxv=max(tree[x].maxv,tree[x].val);
	tree[x].node=x;
	if(tree[lson].maxv==tree[x].maxv)tree[x].node=tree[lson].node;
	if(tree[rson].maxv==tree[x].maxv)tree[x].node=tree[rson].node;
}
void pushr(int x)
{
	swap(lson,rson);
	tree[x].rev^=1;
}
void pushdown(int x)
{
	if(tree[x].rev)
	{
		pushr(lson);
		pushr(rson);
		tree[x].rev=0;
	}
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
}
int st[100005],top;
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
void access(int x)
{
//	printf("access(%d):\n",x);
	int last=0;
	while(x)
	{
//		printf("%d %d size=%d\n",x,last,tree[x].size+tree[x].tot);
		splay(x);
//		printf("%d %d size=%d\n",x,last,tree[x].size+tree[x].tot);
		tree[x].tot-=tree[last].size+tree[last].tot;
		tree[x].tot+=tree[rson].size+tree[rson].tot;
//		printf("%d %d size=%d\n",x,last,tree[x].size+tree[x].tot);
		rson=last;
		pushup(x);
//		printf("%d %d size=%d\n",x,last,tree[x].size+tree[x].tot);
		last=x;
		x=tree[x].parent;
	}
}
void makeroot(int x)
{
	access(x);
	splay(x);
	pushr(x);
}
int findroot(int x)
{
	access(x);
	splay(x);
	pushdown(x);
	while(lson)
	{
		x=lson;
		pushdown(x);
	}
	return x;
}
void split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
}
void cut(int x,int y)
{
//	printf("cut(%d,%d)\n",x,y);
	makeroot(x);
	access(y);
	splay(y);
//	printf("%d %d\n",tree[y].size,tree[y].tot);
	num-=(tree[y].size+tree[y].tot)&1;
//	printf("num=%d\n",num);
	tree[y].child[0]=tree[x].parent=0;
	pushup(y);
//	printf("%d %d\n",tree[x].size,tree[x].tot);
//	printf("%d %d\n",tree[y].size,tree[y].tot);
	num+=(tree[y].size+tree[y].tot)&1;
	num+=(tree[x].size+tree[x].tot)&1;
//	printf("num=%d\n",num);
}
void link(int x,int y)
{
//	printf("link(%d,%d)\n",x,y);
//	printf("x=%d,size=%d\ny=%d,size=%d\n",x,tree[x].size+tree[x].tot,y,tree[y].size+tree[y].tot);
	makeroot(x);
	makeroot(y);
//	printf("x=%d,size=%d\ny=%d,size=%d\n",x,tree[x].size+tree[x].tot,y,tree[y].size+tree[y].tot);
	num-=(tree[x].size+tree[x].tot)&1;
	num-=(tree[y].size+tree[y].tot)&1;
	tree[y].parent=x;
	tree[x].tot+=tree[y].size+tree[y].tot;
	num+=(tree[x].size+tree[x].tot)&1;
//	printf("num=%d\n",num);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		tree[i].node=i;
		tree[i].size=1;
	}
	num=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].len);
		tree[i+n].val=e[i].len;
		tree[i+n].maxv=e[i].len;
		tree[i+n].node=i+n;
		int u=e[i].from,v=e[i].to;
		makeroot(u);
		bool flag=1;
		if(findroot(v)==u)
		{
			int now=tree[v].node;
			if(e[now-n].len<e[i].len)flag=0;
			if(flag)
			{
				cut(now,e[now-n].from);
				cut(now,e[now-n].to);
				del.push(make_pair(e[now-n].len,now-n));
			}
		}
		if(flag)
		{
			link(u,i+n);
			link(i+n,v);
			q.push(make_pair(e[i].len,i));
		}
		if(num)
		{
			printf("-1\n");
			continue;
		}
		while(1)
		{
			while(!q.empty()&&!del.empty()&&q.top()==del.top())
			{
				q.pop();
				del.pop();
			}
			int now=q.top().second;
			cut(now+n,e[now].from);
			if(num)
			{
				link(now+n,e[now].from);
				break;
			}
			cut(now+n,e[now].to);
			q.pop();
		}
		while(!q.empty()&&!del.empty()&&q.top()==del.top())
		{
			q.pop();
			del.pop();
		}
		printf("%d\n",q.top().first);
	}
	return 0;
}