#include<bits/stdc++.h>
using namespace std;
int n,q;
const int max_n=3e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
}
int dep[max_n],fath[max_n],sz[max_n],son[max_n];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	fath[x]=fa;
	sz[x]=1;
	son[x]=-1;
	int max_sz=0;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>max_sz)
			{
				max_sz=sz[y];
				son[x]=y;
			}
		}
	}
}
int _top[max_n];
void dfs2(int x,int top_now)
{
	_top[x]=top_now;
	if(son[x]!=-1)
		dfs2(son[x],top_now);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fath[x]&&y!=son[x])
			dfs2(y,y);
	}
}
inline int get_LCA(int x,int y)
{
	while(_top[x]!=_top[y])
	{
		if(dep[_top[x]]<dep[_top[y]])
			swap(x,y);
		x=fath[_top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int a[max_n];
unsigned long long X[max_n];
namespace SegmentTree
{
	const int max_sz=20*3e5+5;
	unsigned long long val[max_sz];
	int ls[max_sz],rs[max_sz],cnt_node;
	void modify(int old,int &p,int l,int r,int k,unsigned long long v)
	{
		p=++cnt_node;
		val[p]=val[old]^v,ls[p]=ls[old],rs[p]=rs[old];
		if(l<r)
		{
			int mid=(l+r)>>1;
			if(k<=mid)
				modify(ls[old],ls[p],l,mid,k,v);
			else
				modify(rs[old],rs[p],mid+1,r,k,v);
		}
	}
	int res;
	void query(int p1,int p2,int p3,int p4,int l,int r)
	{
		if(l==r)
		{ 
			res=l;
			return;
		}
		int mid=(l+r)>>1;
		if(val[ls[p1]]^val[ls[p2]]^val[ls[p3]]^val[ls[p4]])
			query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid);
		else
			query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r);
	}
	void query(int p1,int p2,int p3,int p4,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			if(val[p1]^val[p2]^val[p3]^val[p4])
				query(p1,p2,p3,p4,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid,a,b);
		if(b>mid&&res==-1)
			query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r,a,b);
	}
}
int root[max_n];
void dfs(int x,int fa)
{
	SegmentTree::modify(root[fa],root[x],1,n,a[x],X[a[x]]);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs(y,x);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	dfs1(1,0);
	dfs2(1,1);
    mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
	for(int i=1;i<=n;++i)
		X[i]=rd();
	dfs(1,0);
	while(q--)
	{
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		int p=get_LCA(u,v);
		SegmentTree::res=-1;
		SegmentTree::query(root[u],root[v],root[p],root[fath[p]],1,n,l,r);
		printf("%d\n",SegmentTree::res);
	}
	return 0;
}