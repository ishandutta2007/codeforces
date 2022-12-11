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
	char st[26];
	int top;
	inline void write_int(long long x)
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
const int max_tot=1e6+5;
int End[max_tot],Last[max_tot],Next[max_tot],e;
inline void add_edge(int x,int y)
{
//	fprintf(stderr,"x=%d y=%d\n",x,y);
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int tr[max_tot][26],fail[max_tot],tot;
namespace AC
{
	inline void insert(const char *s,int &id)
	{
		int cur=0;
		for(int i=0;s[i];++i)
		{
			int v=s[i]-'a';
			if(!tr[cur][v])
				tr[cur][v]=++tot;
			cur=tr[cur][v];
		}
		id=cur;
	}
	int que[max_tot],head,tail;
	inline void build()
	{
		head=1,tail=0;
		for(int i=0;i<26;++i)
		{
			int u=tr[0][i];
			if(u)
			{
				add_edge(0,u);
				que[++tail]=u;
			}
		}
		while(head<=tail)
		{
			int u=que[head++];
			for(int i=0;i<26;++i)
			{
				int v=tr[u][i];
				if(v)
				{
					fail[v]=tr[fail[u]][i];
					add_edge(fail[v],v);
					que[++tail]=v;
				}
				else
					tr[u][i]=tr[fail[u]][i];
			}
		}
	}
}
int dfn[max_tot][2],Time;
void dfs(int x)
{
	dfn[x][0]=++Time;
//	fprintf(stderr,"x=%d\n",x);
	for(int i=Last[x];i;i=Next[i])
		dfs(End[i]);
	dfn[x][1]=Time;
}
namespace BIT
{
	int val[max_tot];
	inline void modify(int k,int v)
	{
		for(int i=k;i<=Time;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
const int max_k=1e5+5;
int id[max_k];
bool mark[max_k];
const int max_len=1e6+5;
char s[max_len];
int main()
{
	int n=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=k;++i)
	{
		IO::read_string(s);
		AC::insert(s,id[i]);
	}
	AC::build();
	dfs(0);
	for(int i=1;i<=k;++i)
	{
		mark[i]=true;
		BIT::modify(dfn[id[i]][0],1);
		BIT::modify(dfn[id[i]][1]+1,-1);
	}
	while(n--)
	{
		char op;
		do
		{
			op=IO::read_char();
		}while(op!='+'&&op!='-'&&op!='?');
		if(op=='+')
		{
			int x=IO::read_int();
			if(!mark[x])
			{
				mark[x]=true;
				BIT::modify(dfn[id[x]][0],1);
				BIT::modify(dfn[id[x]][1]+1,-1);
			}
		}
		else if(op=='-')
		{
			int x=IO::read_int();
			if(mark[x])
			{
				mark[x]=false;
				BIT::modify(dfn[id[x]][0],-1);
				BIT::modify(dfn[id[x]][1]+1,1);
			}
		}
		else
		{
			IO::read_string(s);
			int cur=0;
			long long ans=0;
			for(int i=0;s[i];++i)
			{
				cur=tr[cur][s[i]-'a'];
				ans+=BIT::query(dfn[cur][0]);
			}
			IO::write_int(ans);
			IO::write_char('\n');
		}
	}
	IO::flush();
	return 0;
}