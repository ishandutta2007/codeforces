#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct SAM
{
	int child[26];
	int fail;
	int len;
}tree[400005];
struct Edge
{
	int to;
	int nxt;
}e[400005];
struct Tree
{
	#define lc tree[x].child[0]
	#define rc tree[x].child[1]
	#define mid ((l+r)>>1)
	struct Node
	{
		int child[2];
		int sum;
	}tree[10000005];
	int tot;
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		int now=++tot;
		tree[now].sum=tree[x].sum+tree[y].sum;
		tree[now].child[0]=merge(lc,tree[y].child[0]);
		tree[now].child[1]=merge(rc,tree[y].child[1]);
		return now;
	}
	void add(int x,int l,int r,int p,int v)
	{
		tree[x].sum+=v;
		if(l==r)return;
		if(p<=mid)add(lc?lc:lc=++tot,l,mid,p,v);
		else add(rc?rc:rc=++tot,mid+1,r,p,v);
	}
	int query(int x,int l,int r,int p)
	{
		if(!tree[x].sum)return 0;
		if(l==r)return l;
		if(r<=p)
		{
			if(tree[rc].sum)return query(rc,mid+1,r,p);
			return query(lc,l,mid,p);
		}
		if(mid>=p)return query(lc,l,mid,p);
		int ans=query(rc,mid+1,r,p);
		if(ans)return ans;
		return query(lc,l,mid,p);
	}
	#undef lc
	#undef rc
	#undef mid
}T;
int n,edgenum,tot,last,root[400005],head[400005],f[400005],g[400005],st[400005],pos[400005],top;
char s[200005];
void ins(char c,int pos)
{
	int now=++tot;
	tree[now].len=tree[last].len+1;
	int node=last;
	while(node!=-1&&!tree[node].child[c-'a'])
	{
		tree[node].child[c-'a']=now;
		node=tree[node].fail;
	}
	if(node==-1)tree[now].fail=0;
	else
	{
		int cur=tree[node].child[c-'a'];
		if(tree[cur].len==tree[node].len+1)tree[now].fail=cur;
		else
		{
			int clone=++tot;
			tree[clone]=tree[cur];
			tree[clone].len=tree[node].len+1;
			while(node!=-1&&tree[node].child[c-'a']==cur)
			{
				tree[node].child[c-'a']=clone;
				node=tree[node].fail;
			}
			tree[cur].fail=tree[now].fail=clone;
		}
	}
	last=now;
	root[now]=++T.tot;
	T.add(root[now],1,n,pos,1);
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs1(to);
		root[node]=T.merge(root[node],root[to]);
	}
}
void dfs2(int node)
{
	st[++top]=node;
	pos[node]=top;
	if(node)
	{
		int now=pos[g[tree[node].fail]];
		int p=T.query(root[node],1,n,n);
		while(p-T.query(root[st[now+1]],1,n,p-1)+tree[st[now+1]].len<=tree[node].len)now++;
		g[node]=st[now];
		f[node]=f[g[node]]+1;
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs2(to);
	}
	top--;
}
int main()
{
	tree[0].fail=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1)return puts("1"),0;
	for(int i=1;i<=n;i++)ins(s[i],i);
	for(int i=1;i<=tot;i++)add(tree[i].fail,i);
	dfs1(0);
	dfs2(0);
	int ans=0;
	for(int i=1;i<=tot;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}