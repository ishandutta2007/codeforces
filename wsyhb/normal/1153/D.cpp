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
int n,k;
const int max_n=3e5+5;
int End[max_n],Last[max_n],Next[max_n],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int op[max_n],dp[max_n];
int main()
{
	n=IO::read_int();
	for(int i=1;i<=n;++i)
		op[i]=IO::read_int();
	for(int i=2;i<=n;++i)
	{
		int fa=IO::read_int();
		add_edge(fa,i);
	}
	for(int i=1;i<=n;++i)
		k+=!Last[i];
	for(int x=n;x>=1;--x)
	{
		if(!Last[x])
			dp[x]=1;
		else
		{
			if(op[x]==0)
			{
				dp[x]=0;
				for(int i=Last[x];i;i=Next[i])
				{
					int y=End[i];
					dp[x]+=dp[y];
				}
			}
			else
			{
				dp[x]=1e9; 
				for(int i=Last[x];i;i=Next[i])
				{
					int y=End[i];
					dp[x]=min(dp[x],dp[y]);
				}
			}
		}
	}
	printf("%d\n",k-dp[1]+1);
	return 0;
}