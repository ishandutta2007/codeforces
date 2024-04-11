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
const int P=1e9+7;
const int max_n=1e5+5;
struct segment
{
	int l,r;
}s[max_n];
inline bool cmp(const segment &a,const segment &b)
{
	return a.l<b.l;
}
multiset<int> t;
multiset<int>::iterator it; 
int main()
{
	int n=IO::read_int(),x=IO::read_int(),y=IO::read_int();
	for(int i=1;i<=n;++i)
		s[i].l=IO::read_int(),s[i].r=IO::read_int();
	sort(s+1,s+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		it=t.lower_bound(s[i].l);
		if(it!=t.begin())
		{
			--it;
			int R=*it;
			if(1ll*(s[i].l-R)*y<x)
			{
				ans=(ans+1ll*(s[i].r-R)*y)%P;
				t.erase(it);
				t.insert(s[i].r);
				continue;
			}
		}
		ans=(ans+1ll*(s[i].r-s[i].l)*y+x)%P;
		t.insert(s[i].r);
	}
	printf("%d\n",ans);
	return 0;
}