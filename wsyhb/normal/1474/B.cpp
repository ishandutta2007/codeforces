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
bool mark_p[max_n];
int prime[max_n],cnt;
const int max_d=1e5+5;
long long ans[max_d];
int main()
{
	int n=1e5;
	for(int i=2;i<=n;++i)
	{
		if(!mark_p[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*i*prime[j]<=n;++j)
		{
			mark_p[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
	int d=1e4;
	for(int i=1;i<=n;++i)
		ans[i]=1e18;
	for(int i=1;i<=cnt;++i)
		for(int j=i+1;j<=cnt;++j)
		{
			int v=min(prime[i]-1,prime[j]-prime[i]);
			ans[v]=min(ans[v],1ll*prime[j]*prime[i]);
		}
	for(int i=n-1;i>=1;--i)
		ans[i]=min(ans[i],ans[i+1]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int d;
		scanf("%d",&d);
		printf("%lld\n",ans[d]);
	}
	return 0;
}