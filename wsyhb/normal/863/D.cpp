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
const int max_n=2e5+5;
int a[max_n];
const int max_q=2e5+5;
int t[max_q],l[max_q],r[max_q];
int main()
{
	int n=IO::read_int(),q=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	for(int i=1;i<=q;++i)
		t[i]=IO::read_int(),l[i]=IO::read_int(),r[i]=IO::read_int();
	for(int j=1;j<=m;++j)
	{
		int x=IO::read_int();
		for(int i=q;i>=1;--i)
		{
			if(l[i]<=x&&x<=r[i])
			{
				if(t[i]==1)
				{
					if(x==l[i])
						x=r[i];
					else
						--x;
				}
				else
					x=r[i]-(x-l[i]);
			}
		}
		printf("%d%c",a[x],j<m?' ':'\n');
	}
	return 0;
}