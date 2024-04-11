#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return neg?-x:x;
    }
    inline long long read_ll()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            neg=(c=='-');
            c=read_char();
        }
    	long long x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return neg?-x:x;
    }
    char fw[buf_size];
    int pw;
    inline void flush()
    {
        fwrite(fw,1,pw,stdout);
        pw=0;
    }
    inline void write_char(char x)
    {
        fw[pw++]=x;
        if(pw==buf_size)
            flush();
    }
    inline void write_ll(long long x)
    {
        if(!x)
        {
            write_char('0');
            return;
        }
        if(x<0)
        {
            write_char('-');
            x=-x;
        }
        static char st[26];
        int tp=0;
        while(x)
        {
            st[++tp]=x%10^'0';
            x/=10;
        }
        while(tp>0)
            write_char(st[tp--]);
    }
}
int n,q;
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e=1;
long long Len[max_n<<1];
inline void add_edge(int x,int y,long long z)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e,Len[e]=z;
	End[++e]=x,Next[e]=Last[y],Last[y]=e,Len[e]=z;
}
int dep[max_n],fath[max_n],Euler_dfn[max_n],Time,id[max_n<<1],dfn[max_n][2],old[max_n],Time1;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	fath[x]=fa;
	Euler_dfn[x]=++Time;
	id[Time]=x;
	dfn[x][0]=++Time1;
	old[Time1]=x;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			id[++Time]=x;
		}
	}
	dfn[x][1]=Time1;
}
int Log[max_n<<1],f[18][max_n<<1];
inline int Min(int a,int b)
{
	return dep[a]<dep[b]?a:b;
}
inline int get_LCA(int x,int y)
{
	int l=Euler_dfn[x],r=Euler_dfn[y];
	if(l>r)
		swap(l,r);
	int k=Log[r-l+1];
	return Min(f[k][l],f[k][r-(1<<k)+1]);
}
namespace BIT
{
	long long val[max_n];
	inline void modify(int k,long long v)
	{
		for(int i=k;i<=n;i+=i&(-i))
			val[i]+=v;
	}
	inline long long query(int k)
	{
		long long res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
inline long long get_dis(int x,int y)
{
	return BIT::query(dfn[x][0])+BIT::query(dfn[y][0])-2*BIT::query(dfn[get_LCA(x,y)][0]);
}
namespace SegTree
{
	struct Node
	{
		int s,t;
		long long l;
		inline Node() {}
		inline Node(int S,int T)
		{
			s=S,t=T,l=get_dis(S,T);
		}
		inline Node(int S,int T,long long L)
		{
			s=S,t=T,l=L;
		}
	}node[max_n<<2];
	inline bool operator < (const Node &a,const Node &b)
	{
		return a.l<b.l;
	}
	inline Node operator + (const Node &a,const Node &b)
	{
		Node res=max(a,b);
		if(a.s!=b.s)
			res=max(res,Node(a.s,b.s));
		if(a.s!=b.t&&b.s!=b.t)
			res=max(res,Node(a.s,b.t));
		if(a.s!=a.t)
		{
			if(a.t!=b.s)
				res=max(res,Node(a.t,b.s));
			if(a.t!=b.t&&b.s!=b.t)
				res=max(res,Node(a.t,b.t));
		}
		return res;
	}
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			node[p]=Node(old[l],old[l],0);
			return;
		}
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		node[p]=node[ls(p)]+node[rs(p)];
	}
	void modify(int p,int l,int r,int a,int b,int k)
	{
		if(l==r)
			return;
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(ls(p),l,mid,a,b,k);
		else
			modify(rs(p),mid+1,r,a,b,k);
		if(l<=b&&r>=a)
			node[p]=node[ls(p)]+node[rs(p)];
	}
}
int main()
{
	n=IO::read_int(),q=IO::read_int();
	long long w=IO::read_ll();
	for(int i=1;i<=n-1;++i)
	{
		int a=IO::read_int(),b=IO::read_int();
		long long c=IO::read_ll();
		add_edge(a,b,c);
	}
	dfs(1,0);
	assert(Time==2*n-1);
	assert(Time1==n);
	Log[0]=-1;
	for(int i=1;i<=Time;++i)
	{
		Log[i]=Log[i>>1]+1;
		f[0][i]=id[i];
	}
	for(int i=1;i<=Log[Time];++i)
		for(int j=1;j+(1<<i)-1<=Time;++j)
			f[i][j]=Min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=n-1;++i)
	{
		int x=End[i<<1],y=End[i<<1|1];
		long long z=Len[i<<1];
		if(fath[y]!=x)
		{
			swap(x,y);
			swap(End[i<<1],End[i<<1|1]);
		}
		BIT::modify(dfn[y][0],z);
		BIT::modify(dfn[y][1]+1,-z);
	}
	SegTree::build(1,1,n);
	long long ans=0;
	for(int t=1;t<=q;++t)
	{
		int d=IO::read_int();
		long long e=IO::read_ll();
		d=(d+ans)%(n-1)+1;
		e=(e+ans)%w;
		int y=End[d<<1|1];
		long long z=Len[d<<1];
		BIT::modify(dfn[y][0],e-z);
		BIT::modify(dfn[y][1]+1,-(e-z));
		Len[d<<1]=Len[d<<1|1]=e;
		if(dfn[y][0]>1)
			SegTree::modify(1,1,n,dfn[y][0],dfn[y][1],dfn[y][0]-1);
		if(dfn[y][1]<n)
			SegTree::modify(1,1,n,dfn[y][0],dfn[y][1],dfn[y][1]+1);
		ans=SegTree::node[1].l;
		IO::write_ll(ans);
		IO::write_char('\n');
	}
	IO::flush();
	return 0;
}