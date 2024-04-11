#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buffer_size=1e5+5;
	char buf[buffer_size],*S,*T;
	bool flag_EOF;
	inline char read_char()
	{
	    if(S==T)
			T=(S=buf)+fread(buf,1,buffer_size,stdin);
	    return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
	    int flag=1;
	    char c=read_char();
	    while(c<'0'||c>'9')
	    {
	        if(c==EOF)
	        {
	            flag_EOF=true;
	            return 0;
	        }
	        flag=(c=='-'?-1:1);
	        c=read_char();
	    }
	    int x=0;
	    while(c>='0'&&c<='9')
	    {
	        x=x*10+(c^48);
	        c=read_char();
	    }
	    return x*flag;
	}
	char st[13];
	int _top;
	void Write(int x)
	{
		if(!x)
		{
			putchar('0');
			return;
		}
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=2e5+5;
int a[max_n],Hash[max_n],ra,cnt[max_n];
vector<int> edge[max_n];
int dfn[max_n][2],Time,v[max_n];
void dfs_init(int x,int fa)
{
	dfn[x][0]=++Time;
	v[Time]=a[x];
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
			dfs_init(y,x);
	}
	dfn[x][1]=Time;
}
const int max_size=16e6+5;
int val[max_size],ls[max_size],rs[max_size],cnt_node,root[max_n];
void build(int &p,int l,int r)
{
	p=++cnt_node;
	if(l<r)
	{
		int mid=(l+r)>>1;
		build(ls[p],l,mid);
		build(rs[p],mid+1,r);
	}
}
void modify(int old,int &p,int l,int r,int k,int v)
{
	p=++cnt_node;
	val[p]=val[old]+v;
	ls[p]=ls[old],rs[p]=rs[old];
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
void query(int p,int q,int l,int r,int k)
{
	if(l==r)
	{
		res=val[q]-val[p];
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)
		query(ls[p],ls[q],l,mid,k);
	else
		query(rs[p],rs[q],mid+1,r,k);
}
int cnt_in[max_n],cnt_out[max_n];
bool mark_in[max_n],mark_pre[max_n],mark_suf[max_n],mark_out[max_n];
void dfs1(int x,int fa)
{
	mark_in[x]=true;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs1(y,x);
			mark_pre[y]=mark_in[x];
			mark_in[x]&=mark_in[y];
			query(root[dfn[y][0]-1],root[dfn[y][1]],1,ra,a[x]);
			if(res>=1)
				mark_in[x]=false;
		}
	}
	mark_in[x]=true;
	for(int i=int(edge[x].size())-1;i>=0;--i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			mark_suf[y]=mark_in[x];
			mark_in[x]&=mark_in[y];
			query(root[dfn[y][0]-1],root[dfn[y][1]],1,ra,a[x]);
			if(res>=1)
				mark_in[x]=false;
		}
	}
}
void dfs2(int x,int fa)
{
	mark_out[x]=true;
	if(fa!=0)
	{
		mark_out[x]&=mark_out[fa]&mark_pre[x]&mark_suf[x];
		query(root[dfn[x][0]-1],root[dfn[x][1]],1,ra,a[x]);
		if(cnt[a[x]]-res>=1)
			mark_out[x]=false; 
	}
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
			dfs2(y,x);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		Hash[i]=a[i];
	}
	sort(Hash+1,Hash+n+1);
	ra=unique(Hash+1,Hash+n+1)-Hash-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(Hash+1,Hash+ra+1,a[i])-Hash;
		++cnt[a[i]];
	}
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs_init(1,0);
	build(root[0],1,ra);
	for(int i=1;i<=n;++i)
		modify(root[i-1],root[i],1,ra,v[i],1);
	dfs1(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans+=mark_in[i]&mark_out[i];
	printf("%d\n",ans);
	return 0;
}