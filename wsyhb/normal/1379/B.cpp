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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		long long m;
		scanf("%d%d%lld",&l,&r,&m);
		long long L=max(m+l-r,1ll),R=m+r-l;
		int ans_a=-1;
		for(int i=l;i<=r;++i)
		{
			long long a=R/i*i;
			if(a>=L)
			{
				ans_a=i;
				break;
			}
		}
		m-=R/ans_a*ans_a;
		for(int c=l;c<=r;++c)
		{
			long long b=m+c;
			if(b>=l&&b<=r)
			{
				printf("%d %lld %d\n",ans_a,b,c);
				break;
			}
		}
	}
	return 0;
}