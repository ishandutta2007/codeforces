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
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],Len[max_n<<1],e;
inline void add_edge(int x,int y,int z)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	Len[e]=z;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	Len[e]=z;
}
int dp[max_n][2];
inline bool cmp(int x,int y)
{
	return dp[x][1]>dp[y][1];
}
void dfs(int x,int fa)
{
	if(!Last[x])
		return;
	vector<int> son;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			son.push_back(y);
			dfs(y,x);
			dp[y][0]+=Len[i];
			dp[y][1]+=Len[i];
		}
	}
	if(int(son.size())>=k)
		nth_element(son.begin(),son.begin()+(k-1),son.end(),cmp);
	for(int i=1;i<=k-1&&i<=int(son.size());++i)
		dp[x][1]+=dp[son[i-1]][1];
	dp[x][0]=dp[x][1];
	for(int i=k;i<=int(son.size());++i)
		dp[x][0]=max(dp[x][0],dp[x][1]+dp[son[i-1]][0]);
	for(int i=1;i<=k-1&&i<=int(son.size());++i)
		dp[x][0]=max(dp[x][0],dp[x][1]-dp[son[i-1]][1]+(k<=int(son.size())?dp[son[k-1]][1]:0)+dp[son[i-1]][0]);
}
int main()
{
	n=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=n-1;++i)
	{
		int u=IO::read_int(),v=IO::read_int(),c=IO::read_int();
		add_edge(u+1,v+1,c);
	}
	dfs(1,0);
	printf("%d\n",dp[1][0]);
	return 0;
}