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
vector<int> edge[max_n];
bool mark[max_n];
int dp_pre[max_n],dp_suf[max_n],dp[max_n],dp_out[max_n];
void dfs1(int x,int fa)
{
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs1(y,x);
			dp_pre[y]=dp[x];
			if(dp[y]>0)
				dp[x]=max(dp[x],dp[y]+1);
			else if(mark[y])
				dp[x]=max(dp[x],1);
		}
	}
	dp[x]=0;
	for(int i=int(edge[x].size())-1;i>=0;--i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dp_suf[y]=dp[x];
			if(dp[y]>0)
				dp[x]=max(dp[x],dp[y]+1);
			else if(mark[y])
				dp[x]=max(dp[x],1);
		}
	}
}
void dfs2(int x,int fa)
{
	if(fa!=0)
	{
		dp_out[x]=max(max(dp_pre[x],dp_suf[x]),dp_out[fa]);
		dp_out[x]+=(dp_out[x]>0||mark[fa]);
		dp[x]=max(dp[x],dp_out[x]);
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
	int n=IO::read_int(),m=IO::read_int(),d=IO::read_int();
	for(int i=1;i<=m;++i)
	{
		int x=IO::read_int();
		mark[x]=true;
	}
	for(int i=1;i<=n-1;++i)
	{
		int a=IO::read_int(),b=IO::read_int();
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans+=(dp[i]<=d);
	printf("%d\n",ans);
	return 0;
}