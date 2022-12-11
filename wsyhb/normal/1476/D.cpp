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
const int max_n=3e5+5;
char s[max_n];
int dp_l[max_n][2],dp_r[max_n][2]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		dp_l[0][0]=dp_l[0][1]=1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='L')
			{
				dp_l[i][0]=dp_l[i-1][1]+1;
				dp_l[i][1]=1;
			}
			else
			{
				dp_l[i][1]=dp_l[i-1][0]+1;
				dp_l[i][0]=1;
			}
		}
		dp_r[n][0]=dp_r[n][1]=1;
		for(int i=n-1;i>=0;--i)
		{
			if(s[i+1]=='R')
			{
				dp_r[i][0]=dp_r[i+1][1]+1;
				dp_r[i][1]=1;
			}
			else
			{
				dp_r[i][1]=dp_r[i+1][0]+1;
				dp_r[i][0]=1;
			}
		}
		for(int i=0;i<=n;++i)
			printf("%d%c",dp_l[i][0]+dp_r[i][0]-1,i<n?' ':'\n');
	}
    return 0;
}