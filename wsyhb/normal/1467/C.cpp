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
int a[3][max_n],n[3],Min[3];
int main()
{
	for(int i=0;i<3;++i)
		scanf("%d",n+i);
	for(int i=0;i<3;++i)
		for(int j=1;j<=n[i];++j)
			scanf("%d",&a[i][j]);
	long long sum=0;
	for(int i=0;i<3;++i)
		for(int j=1;j<=n[i];++j)
			sum+=a[i][j];
	long long res=1e18;
	for(int i=0;i<3;++i)
	{
		long long s=0;
		Min[i]=1e9;
		for(int j=1;j<=n[i];++j)
			s+=a[i][j],Min[i]=min(Min[i],a[i][j]); 
		res=min(res,s);
	}
	for(int i=0;i<3;++i)
		for(int j=i+1;j<3;++j)
			res=min(res,1ll*Min[i]+Min[j]);
	printf("%lld\n",sum-(res<<1));
	return 0;
}