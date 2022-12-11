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
int n;
const int max_n=3e5+5;
int a[max_n];
inline bool check(int i)
{
	return i>=2&&i<=n-1&&((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		int cnt=0;
		for(int i=1;i<=n;++i)
			cnt+=check(i);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int now=a[i];
			for(int j=i-1;j<=i+1;j+=2)
				for(int k=a[j]-1;k<=a[j]+1;++k)
				{
					int v1=check(i-1)+check(i)+check(i+1);
					a[i]=k;
					int v2=check(i-1)+check(i)+check(i+1);
					a[i]=now;
					ans=min(ans,v2-v1);
				}
		}
		printf("%d\n",cnt+ans);
	}
	return 0;
}