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
const int max_n=1e6+5;
char s[max_n];
int a[max_n],sum[max_n];
const int max_size=1<<20|5;
bool mark[max_size];
int pos[max_size],cnt;
char str[max_n];
int main()
{
	int q=IO::read_int();
	while(q--)
	{
		int n=IO::read_int(),k=IO::read_int();
		char c=IO::read_char();
		while(c<'0'|c>'1')
			c=IO::read_char();
		for(int i=1;i<=n;++i)
		{
			s[i]=c;
			c=IO::read_char();
		}
		for(int i=1;i<=n;++i)
		{
			a[i]='1'-s[i];
			sum[i]=sum[i-1]+a[i];
		}
		int len=min(k,20);
		int now=0;
		for(int i=k-len+1;i<=k;++i)
			now=(now<<1)|a[i];
		for(int i=1;i<=n-k+1;++i)
		{
			if(i>1)
			{
				now=(now<<1)&((1<<len)-1);
				now|=a[i+k-1];
			}
			if(sum[i+k-1-len]-sum[i-1]==0)
			{
				mark[now]=true;
				pos[++cnt]=now;
			}
		}
		int ans=-1;
		for(int i=0;i<(1<<len);++i)
		{
			if(!mark[i])
			{
				ans=i;
				break;
			}
		}
		if(ans==-1)
			puts("NO");
		else
		{
			puts("YES");
			for(int i=k;i>=1;--i)
			{
				str[i]=(ans&1)+'0';
				ans>>=1;
			}
			str[k+1]='\0';
			printf("%s\n",str+1);
		}
		while(cnt>0)
			mark[pos[cnt--]]=false;
	}
	return 0;
}