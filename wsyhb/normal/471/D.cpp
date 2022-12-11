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
const int max_w=2e5+5;
int a[max_n],b[max_w],pi[max_w];
int main()
{
	int n=IO::read_int(),w=IO::read_int();
	if(w==1)
	{
		printf("%d\n",n);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		a[i]=IO::read_int();
		a[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=w;++i)
	{
		b[i]=IO::read_int();
		b[i-1]=b[i]-b[i-1];
	}
	--n,--w;
	pi[1]=0;
	for(int i=2;i<=w;++i)
	{
		int j=pi[i-1];
		while(j>0&&b[i]!=b[j+1])
			j=pi[j];
		j+=(b[i]==b[j+1]);
		pi[i]=j;
	}
	int l=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		while(l>0&&a[i]!=b[l+1])
			l=pi[l];
		l+=(a[i]==b[l+1]);
		ans+=(l==w); 
	}
	printf("%d\n",ans);
	return 0;
}