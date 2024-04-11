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
const int max_len=50+5;
char s[max_len],t[max_len];
const char goal[]={'a','b','a','c','a','b','a'};
vector<int> pos;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int ans=0;
		for(int i=1;i+6<=n;++i)
		{
			bool flag=true;
			for(int j=0;j<=6;++j)
			{
				if(s[i+j]!=goal[j])
				{
					flag=false;
					break;
				}
			}
			if(flag)
				++ans;
		}
		if(ans>0)
		{
			if(ans==1)
			{
				puts("Yes");
				for(int i=1;i<=n;++i)
				{
					if(s[i]=='?')
						s[i]='z';
				}
				printf("%s\n",s+1);
			}
			else
				puts("No");
			continue;
		}
		pos.clear();
		for(int i=1;i+6<=n;++i)
		{
			bool flag=true;
			for(int j=0;j<=6;++j)
			{
				if(s[i+j]!='?'&&s[i+j]!=goal[j])
				{
					flag=false;
					break;
				}
			}
			if(flag)
				pos.push_back(i);
		}
		for(int i=0;i<int(pos.size());++i)
		{
			int x=pos[i];
			for(int j=1;j<=n;++j)
				t[j]=s[j];
			for(int j=0;j<=6;++j)
				t[x+j]=goal[j];
			int cnt=0;
			for(int j=1;j+6<=n;++j)
			{
				bool flag=true;
				for(int k=0;k<=6;++k)
				{
					if(t[j+k]!=goal[k])
					{
						flag=false;
						break;
					}
				}
				cnt+=flag;
			}
			if(cnt==1)
			{
				ans=1;
				for(int j=1;j<=n;++j)
				{
					if(t[j]=='?')
						t[j]='z';
				}
				t[n+1]='\0';
				puts("Yes");
				printf("%s\n",t+1);
				break;
			}
		}
		if(!ans)
			puts("No");
	}
	return 0;
}