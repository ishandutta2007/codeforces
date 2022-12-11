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
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_len=2e5+5;
char s[max_len];
int cnt[5];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l=1,r=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=1e9;
		while(r<n)
		{
			++r;
			++cnt[s[r]-'0'];
			while(l<=r&&cnt[s[l]-'0']>1)
			{
				--cnt[s[l]-'0'];
				++l;
			}
			if(cnt[1]>0&&cnt[2]>0&cnt[3]>0)
				ans=min(ans,r-l+1);
		}
		if(ans<1e9)
			printf("%d\n",ans);
		else
			puts("0");
	}
	return 0;
}