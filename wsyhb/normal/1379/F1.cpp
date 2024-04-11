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
int n,m,q;
const int max_q=2e5+5;
int x[max_q],y[max_q];
char op[max_q];//L or R
const int max_n=2e5+5;
int a[max_n],b[max_n];
inline bool check(int v)
{
	for(int i=1;i<=n;++i)
		a[i]=m+1,b[i]=0;
	for(int i=1;i<=v;++i)
	{
		if(op[i]=='L')
			a[x[i]]=min(a[x[i]],y[i]);
		else
			b[x[i]]=max(b[x[i]],y[i]); 
	}
	for(int i=2;i<=n;++i)
		a[i]=min(a[i],a[i-1]);
	for(int j=n-1;j>=1;--j)
		b[j]=max(b[j],b[j+1]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=b[i])
			return false;
	}
	return true; 
}
int main()
{
	n=IO::read_int(),m=IO::read_int(),q=IO::read_int();
	for(int i=1;i<=q;++i)
	{
		x[i]=IO::read_int(),y[i]=IO::read_int();
		if(x[i]&1)
		{
			x[i]=(x[i]+1)>>1;
			y[i]=(y[i]+1)>>1;
			op[i]='L'; 
		}
		else
		{
			x[i]>>=1;
			y[i]>>=1;
			op[i]='R';
		}
	}
	int l=1,r=q,mid,res=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	for(int i=1;i<=res;++i)
		puts("YES");
	for(int i=res+1;i<=q;++i)
		puts("NO");
	return 0;
}