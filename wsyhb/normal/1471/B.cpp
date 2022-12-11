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
int a[max_n],b[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d%d",&n,&x);
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			b[i]=a[i];
			ans+=a[i];
		}
		while(1)
		{
			bool flag=false;
			for(int i=1;i<=n;++i)
			{
				if(b[i]%x==0)
				{
					ans+=a[i];
					b[i]/=x;
				}
				else
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}