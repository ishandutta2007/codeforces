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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			puts("0");
			continue;
		}
		if(n==2)
		{
			puts("1");
			continue;
		}
		if(n==3)
		{
			puts("2");
			continue;
		}
		if(n%2==0)
			puts("2");
		else
			puts("3");
	}
	return 0;
}