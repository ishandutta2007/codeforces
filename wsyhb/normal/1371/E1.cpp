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
int a[max_n],b[max_n],cnt[max_n];
vector<int> ans;
int main()
{
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int x=1;x<=2000;++x)
	{
		for(int i=1;i<=n;++i)
			cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			b[i]=max(min(a[i]-x+1,n+1),1);
			++cnt[b[i]];
		}
		for(int i=1;i<=n;++i)
			cnt[i]+=cnt[i-1];
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			int now=cnt[i]-(i-1);
			if(now<=0||now>=p)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			ans.push_back(x);
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<int(ans.size());++i)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}