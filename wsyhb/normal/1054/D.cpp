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
int xor_sum[max_n],num[max_n];
map<int,int> cnt;
inline long long C2(int x)
{
	return 1ll*x*(x-1)>>1;
}
int main()
{
	int n=IO::read_int(),k=IO::read_int(),t=(1<<k)-1;
	for(int i=1;i<=n;++i)
	{
		int a=IO::read_int(),x=xor_sum[i-1]^a;
		xor_sum[i]=x,num[i]=min(x,x^t),++cnt[num[i]];
	}
	++cnt[0];
	long long ans=C2(n+1);
	for(int i=1;i<=n;++i)
	{
		int k=cnt[num[i]];
		cnt[num[i]]=0;
		ans-=C2(k>>1)+C2((k+1)>>1);
	}
	printf("%lld\n",ans);
	return 0;
}