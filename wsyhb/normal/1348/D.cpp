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
vector<int> Ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=-1;
		for(int i=1;i+1<=n;++i)
		{
			int d=i;
			int now=n-d-1;
			int Last=1;
			Ans.clear();
			for(int j=d;j>=1;--j)
			{
				int cnt=min(now/j,Last);
				Ans.push_back(cnt);;
				now-=cnt*j;
				Last+=cnt; 
			}
			if(now==0)
			{
				ans=i;
				break;
			}
		}
		if(ans==-1)
			puts("-1");
		else
		{
			printf("%d\n",ans);
			for(int i=0;i<ans;++i)
				printf("%d%c",Ans[i],i+1<ans?' ':'\n');
		}
	}
	return 0;
}