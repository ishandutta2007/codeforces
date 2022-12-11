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
	inline void Write(int x)
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
const int max_n=1e6+5;
int End[max_n],Last[max_n],Next[max_n],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int cnt[max_n],dep[max_n],low[max_n];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	low[x]=1e9;
	int cnt_son=0;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			if(low[y]<=dep[x]+k)
			{
				cnt[x]+=cnt[y],cnt[y]=0;
				low[x]=min(low[x],low[y]);
			}
			++cnt_son;
		}
	}
	if(cnt_son==0)
		cnt[x]=1,low[x]=dep[x];
}
void dfs_solve(int x,int fa)
{
	cnt[x]+=cnt[fa];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs_solve(y,x);
	}
}
int main()
{
	n=IO::read_int(),k=IO::read_int();
	for(int i=2;i<=n;++i)
	{
		int fa=IO::read_int();
		add_edge(fa,i);
	}
	dfs(1,0);
	dfs_solve(1,0);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}