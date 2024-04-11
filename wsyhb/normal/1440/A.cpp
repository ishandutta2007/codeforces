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
const int max_n=1e3+5;
char str[max_n]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c0,c1,h;
		scanf("%d%d%d%d%s",&n,&c0,&c1,&h,str+1);
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;++i)
		{
			if(str[i]=='0')
				++cnt0;
			else
				++cnt1;
		}
		if(c0>c1)
		{
			swap(c0,c1);
			swap(cnt0,cnt1);
		}
		if(c1-c0<=h)
			printf("%d\n",c0*cnt0+c1*cnt1);
		else
			printf("%d\n",c0*cnt0+(c0+h)*cnt1);
	}
	return 0;
}