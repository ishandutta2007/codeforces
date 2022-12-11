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
const int max_n=100+5;
int a[max_n],b[max_n];
const int max_w=1e4+5;
double dp[2][max_n][max_w],ans[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	int w=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",a+i,b+i);
		w+=a[i];
	}
	for(int j=0;j<=n;++j)
		for(int k=0;k<=w;++k)
			dp[0][j][k]=-1e9;
	dp[0][0][0]=0;
	for(int i=0;i<n;++i)
	{
		int x=i&1,y=x^1;
		for(int j=0;j<=n;++j)
			for(int k=0;k<=w;++k)
				dp[y][j][k]=-1e9;
		for(int j=0;j<=i;++j)
			for(int k=0;k<=w;++k)
			{
				if(dp[x][j][k]>-1e9)
				{
					dp[y][j+1][k+a[i+1]]=max(dp[y][j+1][k+a[i+1]],dp[x][j][k]+b[i+1]);
					dp[y][j][k]=max(dp[y][j][k],dp[x][j][k]+b[i+1]*0.5);
				}
			}
	}
	int x=n&1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=w;++j)
			ans[i]=max(ans[i],min(1.0*j,dp[x][i][j]));
	for(int i=1;i<=n;++i)
		printf("%.11lf%c",ans[i],i<n?' ':'\n');
	return 0;
}