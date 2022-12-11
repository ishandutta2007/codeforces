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
const int max_n=1e5+5;
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
int dfn[max_n][2],Time,dep[max_n];
void dfs(int x,int fa)
{
	dfn[x][0]=++Time;
	dep[x]=dep[fa]+1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs(y,x);
	}
	dfn[x][1]=Time;
}
int root[max_n],cnt_node;
const int max_size=35e6+5;
int val[max_size],ls[max_size],rs[max_size];
void build(int &p,int l,int r)
{
	p=++cnt_node;
	val[p]=1e9;
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
	ls[p]=ls[old],rs[p]=rs[old];
	val[p]=min(val[old],v);
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
void query(int p,int l,int r,int a,int b)
{
	if(!p)
		return;
	if(a<=l&&r<=b)
	{
		res=min(res,val[p]);
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid)
		query(ls[p],l,mid,a,b);
	if(b>mid)
		query(rs[p],mid+1,r,a,b);
}
int a[max_n],id[max_n],pos[max_n];
inline bool cmp(int x,int y)
{
	return dep[x]<dep[y];
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		id[i]=i;
	}
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	dfs(r,0);
	sort(id+1,id+n+1,cmp);
	build(root[0],1,n);
	int max_dep=dep[id[n]];
	val[0]=1e9;
	for(int i=1;i<=n;++i)
	{
		int x=id[i];
		modify(root[i-1],root[i],1,n,dfn[x][0],a[x]);
		if(i==n||dep[x]!=dep[id[i+1]])
			pos[dep[x]]=i;
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		int x=(p+res)%n+1;
		int k=(q+res)%n;
		int d=min(dep[x]+k,max_dep);
		res=1e9;
		query(root[pos[d]],1,n,dfn[x][0],dfn[x][1]);
		printf("%d\n",res);
	}
	return 0;
}