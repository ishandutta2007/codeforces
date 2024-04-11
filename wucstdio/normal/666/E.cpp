#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Tree
{
	#define lson tree[x].child[0]
	#define rson tree[x].child[1]
	#define mid (l+r)/2
	struct Node
	{
		int child[2];
		int maxv,pos;
	}tree[1000005];
	int tot;
	void pushup(int x)
	{
		tree[x].maxv=max(tree[lson].maxv,tree[rson].maxv);
		tree[x].pos=tree[lson].maxv>=tree[rson].maxv?tree[lson].pos:tree[rson].pos;
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y)return x+y;
		if(l==r)
		{
			tree[x].maxv+=tree[y].maxv;
			tree[x].pos=l;
			return x;
		}
		lson=merge(lson,tree[y].child[0],l,mid);
		rson=merge(rson,tree[y].child[1],mid+1,r);
		pushup(x);
		return x;
	}
	void add(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			tree[x].maxv+=v;
			tree[x].pos=l;
			return;
		}
		if(p<=mid)add(lson?lson:lson=++tot,l,mid,p,v);
		else add(rson?rson:rson=++tot,mid+1,r,p,v);
		pushup(x);
	}
	pair<int,int>query(int x,int l,int r,int from,int to)
	{
		if(l>=from&&r<=to)return make_pair(tree[x].maxv,tree[x].pos?tree[x].pos:l);
		pair<int,int>ans=make_pair(0,from),res;
		if(from<=mid)
		{
			res=query(lson,l,mid,from,to);
			if(res.first>ans.first)ans=res;
		}
		if(to>mid)
		{
			res=query(rson,mid+1,r,from,to);
			if(res.first>ans.first)ans=res;
		}
		return ans;
	}
	#undef lson
	#undef rson
	#undef mid
}T;
struct SAM
{
	int child[26];
	int fail;
	int len;
}tree[1100005];
struct Query
{
	int id;
	int pos;
	int l,r;
}a[500005];
int n,m,q,tot,last,c[1100005],sa[1100005],root[1100005],anc[21][1100005],pos[1100005];
pair<int,int>ans[500005];
char s[500005],_t[500005],*t[50005];
vector<Query>st[1100005];
void insert(int c)
{
	if(tree[last].child[c])
	{
		int node=last;
		int cur=tree[last].child[c];
		if(tree[cur].len==tree[node].len+1)last=cur;
		else
		{
			int clone=++tot;
			tree[clone]=tree[cur];
			tree[clone].len=tree[node].len+1;
			while(tree[node].child[c]==cur)
			{
				tree[node].child[c]=clone;
				node=tree[node].fail;
			}
			tree[cur].fail=clone;
			last=clone;
		}
		return;
	}
	int now=++tot;
	int node=last;
	tree[now].len=tree[last].len+1;
	while(node!=-1&&!tree[node].child[c])
	{
		tree[node].child[c]=now;
		node=tree[node].fail;
	}
	if(node==-1)tree[now].fail=0;
	else
	{
		int cur=tree[node].child[c];
		if(tree[cur].len==tree[node].len+1)tree[now].fail=cur;
		else
		{
			int clone=++tot;
			tree[clone]=tree[cur];
			tree[clone].len=tree[node].len+1;
			while(tree[node].child[c]==cur)
			{
				tree[node].child[c]=clone;
				node=tree[node].fail;
			}
			tree[now].fail=tree[cur].fail=clone;
		}
	}
	last=now;
}
int main()
{
	scanf("%s",s+1);
	tree[0].fail=-1;
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		insert(s[i]-'a');
		pos[i]=last;
	}
	scanf("%d",&m);
	t[1]=_t;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t[i]+1);
		n=(int)strlen(t[i]+1);
		last=0;
		for(int j=1;j<=n;j++)
		  insert(t[i][j]-'a');
		t[i+1]=t[i]+n+1;
	}
	for(int i=1;i<=m;i++)
	{
		n=(int)strlen(t[i]+1);
		int node=0;
		for(int j=1;j<=n;j++)
		{
			while(node!=-1&&!tree[node].child[t[i][j]-'a'])
			  node=tree[node].fail;
			if(node==-1)node=0;
			else node=tree[node].child[t[i][j]-'a'];
			T.add(root[node]?root[node]:root[node]=++T.tot,1,m,i,1);
		}
	}
	for(int i=1;i<=tot;i++)anc[0][i]=tree[i].fail;
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=tot;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int pl,pr;
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&pl,&pr);
		a[i].id=i;
		int now=pos[pr];
		for(int j=20;j>=0;j--)
		  if(tree[anc[j][now]].len>=pr-pl+1)
		    now=anc[j][now];
		a[i].pos=now;
		st[now].push_back(a[i]);
	}
	for(int i=1;i<=tot;i++)c[tree[i].len]++;
	for(int i=1;i<=tot;i++)c[i]+=c[i-1];
	for(int i=tot;i>=1;i--)sa[c[tree[i].len]--]=i;
	for(int i=tot;i>=1;i--)
	{
		int node=sa[i];
		int x=(int)st[node].size();
		for(int j=0;j<x;j++)
			ans[st[node][j].id]=T.query(root[node],1,m,st[node][j].l,st[node][j].r);
		root[tree[node].fail]=T.merge(root[tree[node].fail],root[node],1,m);
	}
	for(int i=1;i<=q;i++)printf("%d %d\n",ans[i].second,ans[i].first);
	return 0;
}