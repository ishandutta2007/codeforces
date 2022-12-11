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
const int max_n=2e5+5;
int a[max_n];
long long sum[max_n];
long long Min[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
			sum[i]=a[i]-sum[i-1];
		Min[n]=sum[n],Min[n-1]=sum[n-1];
		for(int i=n-2;i>=1;--i)
			Min[i]=min(Min[i+2],sum[i]);
		int pos=n-1;
		for(int i=1;i<=n-1;++i)
		{
			if(sum[i]<0)
			{
				pos=i;
				break;
			}
		}
		string ans="NO";
		if(Min[1]>=0&&Min[2]>=0&&sum[n]==0)
			ans="YES";
		else
		{
			for(int i=1;i<=pos;++i)
			{
				if(sum[i]-a[i]+a[i+1]<0||(i+2<=n&&Min[i+2]+2ll*(a[i+1]-a[i])<0)||(i+1<=n&&Min[i+1]+2ll*(a[i]-a[i+1])<0))
					continue;
				if((n^i)&1)
				{
					if(sum[n]-a[i+1]*2ll+a[i]*2ll==0)
					{
						ans="YES";
						break;
					}
				}
				else
				{
					if(sum[n]-a[i]*2ll+a[i+1]*2ll==0)
					{
						ans="YES";
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}