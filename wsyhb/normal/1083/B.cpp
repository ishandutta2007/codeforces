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
	inline void read_string(char *s)
	{
		char x;
		do
		{
			x=read_char();
		}while(x<'a'||x>'z');
		int len=0;
		while(x>='a'&&x<='z')
		{
			s[len++]=x;
			x=read_char();
		}
		s[len]='\0';
	}
	char fw[buffer_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
	}
	inline void write_char(char x)
	{
		if(pw==buffer_size)
		{
			flush();
			pw=0;
		}
		fw[pw++]=x;
	}
	char st[13];
	int top;
	inline void write_int(int x)
	{
		if(!x)
		{
			write_char('0');
			return;
		}
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		while(x)
		{
			st[++top]=x%10+'0';
			x/=10;
		}
		while(top>0)
			write_char(st[top--]);
	}
	inline void write_string(const char *s)
	{
		for(int i=0;s[i];++i)
			write_char(s[i]);
	}
}
const int max_n=5e5+5;
char s[max_n],t[max_n]; 
int main()
{
	int n=IO::read_int(),k=IO::read_int();
	IO::read_string(s+1),IO::read_string(t+1);
	int now=0;
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		now=now*2+(t[i]-s[i]);
		if(now+1>=k)
		{
			ans+=1ll*k*(n-i+1);
			break;
		}
		ans+=now+1;
	}
	printf("%lld\n",ans);
	return 0;
}