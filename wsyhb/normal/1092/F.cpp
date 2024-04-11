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
int a[max_n];
long long sum[max_n],f[max_n];
void dfs1(int x,int fa)
{
	sum[x]=a[x];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			sum[x]+=sum[y];
			f[x]+=f[y]+sum[y];
		}
	}
}
void dfs2(int x,int fa)
{
	if(fa)
		f[x]+=f[fa]-(f[x]+sum[x])+(sum[1]-sum[x]);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs2(y,x);
	}
}
int main()
{
	int n=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	for(int i=1;i<=n-1;++i)
	{
		int x=IO::read_int(),y=IO::read_int();
		add_edge(x,y);
	}
	dfs1(1,0);
	dfs2(1,0);
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}