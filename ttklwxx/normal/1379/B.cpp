#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
signed main()
{
	int t,l,r,m,a,b,c;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l=read();
		r=read();
		m=read();
		a=-1;
		b=-1;
		c=-1;
		for(int i=l;i<=r;i++)
		{
			if(m>=i&&m%i<=r-l)
			{
				a=i;
				b=l+m%i;
				c=l;
				break;
			}
			else if(m%i>=i-r+l)
			{
				a=i;
				b=r-i+m%i;
				c=r;
				break;
			}
		}
		printf("%lld %lld %lld\n",a,b,c);
	}
	return 0;
}