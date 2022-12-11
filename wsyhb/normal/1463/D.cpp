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
const int max_n=2e5+5;
int a[max_n],b[max_n];
set<int> s1,s2;
set<int>::iterator it;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		s1.clear(),s2.clear();
		a[0]=0,a[n+1]=n<<1|1;
		for(int i=0;i<=n;++i)
			for(int j=a[i]+1;j<=a[i+1]-1;++j)
				s1.insert(j),s2.insert(j);
		int x_max=0;
		for(int i=n;i>=1;--i)
		{
			if(a[i]<*(--s1.end()))
			{
				++x_max;
				s1.erase(--s1.end()); 
			}
			else
				s1.erase(s1.begin());
		}
		int x_min=n;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>*s2.begin())
			{
				--x_min;
				s2.erase(s2.begin());
			}
			else
				s2.erase(--s2.end());
		}
		printf("%d\n",x_max-x_min+1);
	}
	return 0;
}