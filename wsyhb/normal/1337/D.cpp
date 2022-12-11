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
int r[max_n],g[max_n],b[max_n];
inline long long get_ans(int a[],int na,int b[],int nb,int c[],int nc)
{
	long long res=4e18;
	int i=1,j=1;
	for(int k=1;k<=nb;++k)
	{
		int y=b[k];
		while(i<=na&&a[i]<=y)
			++i;
		if(i==1)
			continue;
		int x=a[i-1];
		while(j<=nc&&c[j]<y)
			++j;
		if(j>nc)
			break;
		int z=c[j];
		res=min(res,1ll*(x-y)*(x-y)+1ll*(y-z)*(y-z)+1ll*(z-x)*(z-x));
	}
	return res;
}
int main()
{
	int t=IO::read_int();
	while(t--)
	{
		int nr=IO::read_int(),ng=IO::read_int(),nb=IO::read_int();
		for(int i=1;i<=nr;++i)
			r[i]=IO::read_int();
		sort(r+1,r+nr+1);
		for(int i=1;i<=ng;++i)
			g[i]=IO::read_int();
		sort(g+1,g+ng+1);
		for(int i=1;i<=nb;++i)
			b[i]=IO::read_int();
		sort(b+1,b+nb+1);
		long long ans=get_ans(r,nr,g,ng,b,nb);
		ans=min(ans,get_ans(r,nr,b,nb,g,ng));
		ans=min(ans,get_ans(g,ng,r,nr,b,nb));
		ans=min(ans,get_ans(g,ng,b,nb,r,nr));
		ans=min(ans,get_ans(b,nb,r,nr,g,ng));
		ans=min(ans,get_ans(b,nb,g,ng,r,nr));
		printf("%lld\n",ans);
	}
	return 0;
}