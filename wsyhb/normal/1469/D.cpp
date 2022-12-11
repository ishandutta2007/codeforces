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
typedef pair<int,int> P;
vector<P> ans;
vector<int> now;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ans.clear();
		now.clear();
		if(n>=8)
		{
			for(int i=2;i<=n;++i)
			{
				if(i!=4&&i!=8)
					now.push_back(i);
			}
			for(int i=0;i+1<int(now.size());++i)
				ans.push_back(P(now[i],now[i+1]));
			for(int i=1;i<=6;++i)
				ans.push_back(P(now.back(),8));
			ans.push_back(P(8,4));
			ans.push_back(P(4,8));
			ans.push_back(P(4,8));
		}
		else if(n>=4)
		{
			for(int i=2;i<=n;++i)
			{
				if(i!=2&&i!=4)
					now.push_back(i);
			}
			for(int i=0;i+1<int(now.size());++i)
				ans.push_back(P(now[i],now[i+1]));
			for(int i=1;i<=2;++i)
				ans.push_back(P(now.back(),4));
			ans.push_back(P(4,2));
			ans.push_back(P(4,2));
		}
		else
		{
			ans.push_back(P(3,2));
			ans.push_back(P(3,2));
		}
		printf("%d\n",int(ans.size()));
		for(int i=0;i<int(ans.size());++i)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}