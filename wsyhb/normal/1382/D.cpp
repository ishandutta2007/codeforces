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
const int max_n=2e3+5;
int p[max_n<<1];
vector<int> v;
int dp[max_n<<1];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
			scanf("%d",p+i);
		v.clear();
		for(int i=1;i<=2*n;++i)
		{
			int j=i+1;
			while(j<=2*n&&p[j]<=p[i])
				++j;
			v.push_back(j-i);
			i=j-1;
		}
		for(int i=1;i<=2*n;++i)
			dp[i]=false;
		dp[0]=true;
		for(int k=0;k<int(v.size());++k)
		{
			int now=v[k];
			for(int i=2*n;i>=now;--i)
				dp[i]|=dp[i-now];
		}
		if(dp[n])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}