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
vector<int> odd,even;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		odd.clear(),even.clear();
		for(int i=1;i<=2*n;++i)
		{
			int x;
			scanf("%d",&x);
			if(x&1)
				odd.push_back(i);
			else
				even.push_back(i);
		}
		for(int i=1;i<=n-1;++i)
		{
			if((int)odd.size()>=2)
			{
				printf("%d ",odd.back());
				odd.pop_back();
				printf("%d\n",odd.back());
				odd.pop_back();
			}
			else
			{
				printf("%d ",even.back());
				even.pop_back();
				printf("%d\n",even.back());
				even.pop_back();
			}
		}
	}
	return 0;
}