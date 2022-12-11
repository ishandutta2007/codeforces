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
const int max_len=1e5+5;
char s[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int px,py;
		scanf("%d%d%s",&px,&py,s);
		int len=strlen(s);
		int cnt_U=0,cnt_D=0,cnt_R=0,cnt_L=0;
		for(int i=0;i<len;++i)
		{
			if(s[i]=='U')
				++cnt_U;
			else if(s[i]=='D')
				++cnt_D;
			else if(s[i]=='R')
				++cnt_R;
			else
				++cnt_L;
		}
		bool flag=true;
		if(px>0)
		{
			if(cnt_R<px)
				flag=false;
		}
		else
		{
			if(cnt_L<-px)
				flag=false;
		}
		if(py>0)
		{
			if(cnt_U<py)
				flag=false;
		}
		else
		{
			if(cnt_D<-py)
				flag=false;
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	} 
	return 0;
}