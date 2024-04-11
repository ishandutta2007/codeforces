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
const int max_n=5e5+5;
int a[max_n],Last[max_n];
vector<int> pos[max_n];
bool mark[max_n];
int dp[max_n][2];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<(int)pos[i].size();++j)
			Last[pos[i][j]]=pos[i][j-1];
		if(pos[i].size())
			mark[pos[i].back()]=true;
	}
	int mx1=0;
	for(int i=1;i<=n;++i)
	{
		if(!Last[i])
			dp[i][0]=dp[i][1]=mx1+1;
		else
		{
			dp[i][0]=max(mx1,max(dp[Last[i]][0],dp[Last[i]][1]))+1;
			dp[i][1]=dp[Last[i]][1]+1;
		}
		if(mark[i])
			mx1=max(mx1,dp[i][1]);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,max(dp[i][0],dp[i][1]));
	printf("%d\n",n-ans);
	return 0;
}