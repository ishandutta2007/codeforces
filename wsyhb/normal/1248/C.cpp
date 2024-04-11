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
const int P=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=P?P:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a-b<0?P:0);
}
inline void mul(int &a,int b)
{
	a=1ll*a*b%P;
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=P?P:0);
}
inline int get_dif(int a,int b)
{
	return a-b+(a-b<0?P:0);
}
inline int get_pro(int a,int b)
{
	return 1ll*a*b%P;
}
const int max_n=1e5+5;
int f[max_n];
int main()
{
	int n,m;
	cin>>n>>m;
	--n,--m;
	f[1]=f[2]=2;
	for(int i=3;i<=max(n,m);++i)
		f[i]=get_sum(f[i-1],f[i-2]);
	int ans=2;
	for(int i=1;i<=n;++i)
		add(ans,f[i]);
	for(int i=1;i<=m;++i)
		add(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}