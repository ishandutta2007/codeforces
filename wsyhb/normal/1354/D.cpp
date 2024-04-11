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
int n,q;
const int max_n=1e6+5;
const int max_q=1e6+5;
int a[max_n],k[max_q];
int cnt[2];
inline bool check(int x)
{
	cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;++i)
		++cnt[a[i]>x];
	for(int i=1;i<=q;++i)
	{
		if(k[i]>0)
			++cnt[k[i]>x];
		else
		{
			if(cnt[0]>=-k[i])
				--cnt[0];
			else
				--cnt[1];
		}
	}
	return cnt[0]>0;
}
int main()
{
	n=IO::read_int(),q=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	for(int i=1;i<=q;++i)
		k[i]=IO::read_int();
	int L=1,R=n,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))
			ans=mid,R=mid-1;
		else
			L=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}