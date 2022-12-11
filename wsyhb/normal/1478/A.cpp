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
inline int get_power(int a,int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
            mul(res,a);
        mul(a,a);
        n>>=1;
    }
    return res;
}
const int max_n=100+5;
int a[max_n];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		int cnt=0,now=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]!=a[i-1])
			{
				cnt=max(cnt,now);
				now=1;
			}
			else
				++now;
		}
		cnt=max(cnt,now);
		printf("%d\n",cnt);
	 } 
    return 0;
}