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
const int max_m=2e5+5;
long long a[max_n],b[max_m];
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=m;++i)
		scanf("%lld",b+i);
	if(n==1)
	{
		for(int i=1;i<=m;++i)
			printf("%lld%c",a[1]+b[i],i<m?' ':'\n');
		return 0;
	}
	long long d=a[2]-a[1];
	for(int i=3;i<=n;++i)
		d=gcd(d,a[i]-a[1]);
	for(int i=1;i<=m;++i)
		printf("%lld%c",gcd(d>0?d:-d,a[1]+b[i]),i<m?' ':'\n');
	return 0;
}