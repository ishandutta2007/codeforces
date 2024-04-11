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
const int max_n=1e3+5;
int r[max_n],b[max_n];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%1d",r+i);
		for(int i=1;i<=n;++i)
			scanf("%1d",b+i);
		int cnt_red=0,cnt_blue=0,cnt_equal=0;
		for(int i=1;i<=n;++i)
		{
			if(r[i]>b[i])
				++cnt_red;
			else if(r[i]<b[i])
				++cnt_blue;
			else if(r[i]==b[i])
				++cnt_equal;
		}
		if(cnt_red>cnt_blue)
			puts("RED");
		else if(cnt_red==cnt_blue)
			puts("EQUAL");
		else if(cnt_red<cnt_blue)
			puts("BLUE");
	}
	return 0;
}