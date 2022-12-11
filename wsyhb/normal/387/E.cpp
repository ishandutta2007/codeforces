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
int n,k;
const int max_n=1e6+5;
int pos[max_n];
bool vis[max_n];
set<int> s;
set<int>::iterator it;
namespace BIT
{
	int c[max_n];
	inline void modify(int p,int v)
	{
		if(p>0)
		{
			for(int i=p;i<=n;i+=i&(-i))
				c[i]+=v;
		}
	}
	inline int query(int p)
	{
		int res=0;
		for(int i=p;i>0;i-=i&(-i))
			res+=c[i];
		return res;
	}
}
int main()
{
	n=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		int p=IO::read_int();
		pos[p]=i;
	}
	for(int i=1;i<=k;++i)
	{
		int b=IO::read_int();
		vis[b]=true;
	}
	for(int i=1;i<=n;++i)
		BIT::modify(i,1);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i])
			s.insert(pos[i]);
		else
		{
			int l=1,r=n;
			it=s.lower_bound(pos[i]);
			if(it!=s.end())
				r=*it-1;
			if(it!=s.begin())
				l=*(--it)+1;
			ans+=BIT::query(r)-BIT::query(l-1);
			BIT::modify(pos[i],-1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}