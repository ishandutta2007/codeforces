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
const int max_n=100+5;
int a[max_n];
bool vis[max_n];
vector<int> num;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			vis[i]=false;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			vis[a[i]]=true;
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
			cnt+=vis[i];
		if(cnt>k)
		{
			puts("-1");
			continue;
		}
		num.clear();
		for(int i=1;i<=n;++i)
		{
			if(vis[i])
				num.push_back(i);
		}
		for(int i=1;i<=n;++i)
		{
			if(!vis[i]&&(int)num.size()<k)
				num.push_back(i);
		}
		printf("%d\n",n*(int)num.size());
		for(int i=1;i<=n;++i)
			for(int j=0;j<int(num.size());++j)
				printf("%d ",num[j]);
		puts("");
	}
	return 0;
}