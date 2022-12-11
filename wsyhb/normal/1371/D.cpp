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
const int max_n=300+5;
char ans[max_n][max_n];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				ans[i][j]='0';
			ans[i][n+1]='\0';
		}
		for(int d=0;d<=n-1;++d)
			for(int i=1;i<=n&&k>0;++i,--k)
			{
				int j=(i+d)%n;
				if(!j)
					j=n;
				ans[i][j]='1';
			}
		int r_max=0,r_min=1e9,c_max=0,c_min=1e9;
		for(int i=1;i<=n;++i)
		{
			int sum=0;
			for(int j=1;j<=n;++j)
				sum+=ans[i][j]-'0';
			r_max=max(r_max,sum);
			r_min=min(r_min,sum);
		}
		for(int i=1;i<=n;++i)
		{
			int sum=0;
			for(int j=1;j<=n;++j)
				sum+=ans[j][i]-'0';
			c_max=max(c_max,sum);
			c_min=min(c_min,sum);
		}
		printf("%d\n",(r_max-r_min)*(r_max-r_min)+(c_max-c_min)*(c_max-c_min));
		for(int i=1;i<=n;++i)
			printf("%s\n",ans[i]+1);
	}
	return 0;
}