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
	inline void read_string(char *s)
	{
		char x;
		do
		{
			x=read_char();
		}while(x<'a'||x>'z');
		int len=0;
		while(x>='a'&&x<='z')
		{
			s[len++]=x;
			x=read_char();
		}
		s[len]='\0';
	}
	char fw[buffer_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
	}
	inline void write_char(char x)
	{
		if(pw==buffer_size)
		{
			flush();
			pw=0;
		}
		fw[pw++]=x;
	}
	char st[13];
	int top;
	inline void write_int(int x)
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
		while(x)
		{
			st[++top]=x%10+'0';
			x/=10;
		}
		while(top>0)
			write_char(st[top--]);
	}
	inline void write_string(const char *s)
	{
		for(int i=0;s[i];++i)
			write_char(s[i]);
	}
}
int tot;
const int max_tot=3e5+5;
int tr[max_tot][26],fail[max_tot];
bool exist[max_tot];
multiset<int> s[max_tot];
inline void insert(const char *t,int &id)
{
	int cur=0;
	for(int i=0;t[i];++i)
	{
		int v=t[i]-'a';
		if(!tr[cur][v])
			tr[cur][v]=++tot;
		cur=tr[cur][v];
	}
	exist[cur]=true;
	s[cur].insert(0);
	id=cur;
}
int End[max_tot],Last[max_tot],Next[max_tot],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int q[max_tot],head,tail;
inline void build()
{
	head=1,tail=0;
	for(int i=0;i<26;++i)
	{
		int v=tr[0][i];
		if(v)
		{
			add_edge(0,v);
			q[++tail]=v;
		}
	}
	while(head<=tail)
	{
		int u=q[head++];
		for(int i=0;i<26;++i)
		{
			int v=tr[u][i];
			if(v)
			{
				fail[v]=tr[fail[u]][i];
				add_edge(fail[v],v);
				q[++tail]=v;
			}
			else
				tr[u][i]=tr[fail[u]][i];
		}
	}
}
int sz[max_tot],son[max_tot],fath[max_tot];
void dfs1(int x,int fa)
{
	sz[x]=1;
	son[x]=-1;
	fath[x]=fa;
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
int top[max_tot],dfn[max_tot],Time,old[max_tot];
void dfs2(int x,int top_now)
{
	dfn[x]=++Time;
	old[Time]=x;
	top[x]=top_now;
	if(son[x]!=-1)
		dfs2(son[x],top_now);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fath[x]&&y!=son[x])
			dfs2(y,y);
	}
}
int ans;
namespace SegmentTree
{
	int val[max_tot<<2];
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			val[p]=(exist[old[l]]?0:-1);
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		val[p]=max(val[p<<1],val[p<<1|1]);
	}
	void modify(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			val[p]=v;
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(p<<1,l,mid,k,v);
		else
			modify(p<<1|1,mid+1,r,k,v);
		val[p]=max(val[p<<1],val[p<<1|1]);
	}
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			ans=max(ans,val[p]);
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(p<<1,l,mid,a,b);
		if(b>mid)
			query(p<<1|1,mid+1,r,a,b);
	}
}
inline void query(int x)
{
	while(x!=-1)
	{
		SegmentTree::query(1,1,Time,dfn[top[x]],dfn[x]);
		x=fath[top[x]];
	}
}
const int max_n=3e5+5;
int id[max_n],v[max_n];
const int max_len=3e5+5;
char t[max_len];
int main()
{
	int n=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		IO::read_string(t);
		insert(t,id[i]);
	}
	build();
	dfs1(0,-1);
	dfs2(0,0);
	SegmentTree::build(1,1,Time);
	while(m--)
	{
		int op=IO::read_int();
		if(op==1)
		{
			int i=IO::read_int(),x=IO::read_int();
			s[id[i]].erase(s[id[i]].find(v[i]));
			s[id[i]].insert(v[i]=x);
			SegmentTree::modify(1,1,Time,dfn[id[i]],*(--s[id[i]].end()));
		}
		else
		{
			IO::read_string(t);
			int cur=0;
			ans=-1;
			for(int i=0;t[i];++i)
			{
				cur=tr[cur][t[i]-'a'];
				query(cur);
			}
			IO::write_int(ans);
			IO::write_char('\n');
		}
	}
	IO::flush();
	return 0;
}