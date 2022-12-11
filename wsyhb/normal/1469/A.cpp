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
const int max_len=100+5;
char s[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n&1)
		{
			puts("NO");
			continue;
		}
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			cnt1+=(s[i]=='(');
			cnt2+=(s[i]==')');
		}
		if(cnt1>n/2||cnt2>n/2)
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='?')
			{
				if(cnt1<n/2)
				{
					s[i]='(';
					++cnt1;
				}
				else
				{
					s[i]=')';
					++cnt2;
				}
			}
		}
		int cnt=0;
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			cnt+=(s[i]=='('?1:-1);
			if(cnt<0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}