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
char a[max_n],b[max_n];
vector<int> ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s%s",&n,a+1,b+1);
		ans.clear();
		for(int i=1;i<=n;++i)
		{
			int j=i+1;
			while(j<=n&&a[j]==a[i])
				++j;
			if(j-1<n)
				ans.push_back(j-1);
			i=j-1;
		}
		if(a[n]!=b[n])
			ans.push_back(n);
		for(int i=n;i>=1;--i)
		{
			int j=i-1;
			while(j>=1&&b[j]==b[i])
				--j;
			if(j>0)
				ans.push_back(j);
			i=j+1;
		}
		printf("%d%c",int(ans.size()),ans.empty()?'\n':' ');
		for(int i=0;i<int(ans.size());++i)
			printf("%d%c",ans[i],i+1<int(ans.size())?' ':'\n');
	}
	return 0;
}