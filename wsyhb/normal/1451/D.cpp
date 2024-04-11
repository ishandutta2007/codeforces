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
const double sqrt_2=1.4142135623730950488016887242097;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int d,k;
		scanf("%d%d",&d,&k);
		double v=1.0*d/(k*sqrt_2);
		int x=ceil(v);
		if(x==v)
			++x;
		if(1ll*(x-1)*k*(x-1)*k+1ll*x*k*x*k>1ll*d*d)
			puts("Utkarsh");
		else
			puts("Ashish");
	}
	return 0;
}