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
int n,z;
const int max_n=2e5+5;
int x[max_n];
bool check(int v)
{
	for(int i=1;i<=v;++i)
	{
		if(x[i-v+n]-x[i]<z)
			return false;
	}
	return true;
}
int main()
{
	n=IO::read_int(),z=IO::read_int();
	for(int i=1;i<=n;++i)
		x[i]=IO::read_int();
	sort(x+1,x+n+1);
	int l=1,r=n>>1,mid,res=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}