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
const int max_n=1e5+5;
int p[max_n];
typedef pair<int,int> P;
vector<P> ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			p[i]=i;
		long long res=1ll*(n-1)*(n-1);
		swap(p[1],p[n]);
		ans.push_back(P(1,n));
		for(int i=2;i<=n-1;++i)
		{
			if(i-1>=n-i)
			{
				res+=1ll*(i-1)*(i-1);
				swap(p[1],p[i]);
				ans.push_back(P(i,1));
			}
			else
			{
				res+=1ll*(n-i)*(n-i);
				swap(p[n],p[i]);
				ans.push_back(P(i,n));
			}
		}
		printf("%lld\n",res);
		for(int i=1;i<=n;++i)
			printf("%d%c",p[i],i<n?' ':'\n');
		printf("%d\n",int(ans.size()));
		while(ans.size())
		{
			printf("%d %d\n",ans.back().first,ans.back().second);
			ans.pop_back();
		}
	}
	return 0;
}