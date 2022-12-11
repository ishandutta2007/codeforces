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
char s[max_n],t[max_n];
set<int> id[2];
set<int>::iterator it;
int main()
{
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0'&&t[i]=='1')
		{
			id[0].insert(i);
			id[0].insert(i+n);
		}
		else if(s[i]=='1'&&t[i]=='0')
		{
			id[1].insert(i);
			id[1].insert(i+n);
		}
	}
	if(id[0].size()!=id[1].size())
	{
		puts("-1");
		return 0;
	}
	int ans=0;
	while(id[0].size())
	{
		++ans;
		int st=*id[0].begin(),now=st,cnt=0;
		while(1)
		{
			it=id[1].upper_bound(now);
			if(it==id[1].end())
				break;
			int x=*it;
			if(x>n)
			{
				x-=n;
				++cnt;
			}
			if(cnt>1||(cnt==1&&x>st))
				break;
			id[0].erase(now),id[0].erase(now+n);
			id[1].erase(x),id[1].erase(x+n);
			it=id[0].upper_bound(x);
			if(it==id[0].end())
				break;
			now=*it;
			if(now>n)
			{
				now-=n;
				++cnt;
			}
			if(cnt>1||(cnt==1&&now>st))
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
}