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
const int max_n=3e5+5;
int k[max_n],c[max_n];
long long sum[max_n],ans[max_n];
int cnt[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",k+i);
			cnt[i]=0;
		}
		sort(k+1,k+n+1);
		for(int i=1;i<=n;++i)
		{
			++cnt[max(i-k[i]+1,1)];
			--cnt[i+1];
		}
		for(int i=1;i<=n;++i)
			cnt[i]+=cnt[i-1];
		sum[0]=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%d",c+i);
			sum[i]=sum[i-1]+c[i];
		}
		ans[0]=0;
		for(int i=1;i<=n;++i)
			ans[i]=ans[i-1]+c[k[i]];
		long long Ans=ans[n];
		for(int i=0;i<n;++i)
		{
			if(cnt[i+1]==n-i)
				Ans=min(Ans,ans[i]+sum[n-i]);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}