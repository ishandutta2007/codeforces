#include<bits/stdc++.h>
using namespace std;
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
        flag=(c=='-'?-1:flag);
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
	static char st[13];
	int head=0;
	while(x)
	{
		st[++head]=x%10+'0';
		x/=10;
	}
	while(head>0)
		putchar(st[head--]);
}
const int max_size=1e6+5;
int a[max_size];
int main()
{
	int t=read_int();
	while(t--)
	{
		int n=read_int(),k=read_int();
		for(int i=1;i<=n*k;++i)
			a[i]=read_int();
		int cnt=n-(n+1)/2+1;
		long long ans=0;
		for(int i=1;i<=k;++i)
			ans+=a[n*k-cnt*i+1];
		printf("%lld\n",ans);
	}
	return 0;
}