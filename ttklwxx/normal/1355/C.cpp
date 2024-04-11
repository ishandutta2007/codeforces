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
	int a,b,c,d,ans=0;
	a=read();
	b=read();
	c=read();
	d=read();
	if(b-a<=c-b)
	{
		for(int i=a+b;i<=2*b;i++)
		{
			if(i<=c)continue;
			ans+=(i-a-b+1)*(min(i,d+1)-c);
		}
		for(int i=2*b+1;i<=a+c;i++)
		{
		    if(i<=c)continue;
		    ans+=(b-a+1)*(min(i,d+1)-c);
		}
		for(int i=a+c+1;i<=b+c;i++)
		{
		    if(i<=c)continue;
		    ans+=(b+c-i+1)*(min(i,d+1)-c);
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=a+b;i<=a+c;i++)
	{
		if(i<=c)continue;
		ans+=(i-a-b+1)*(min(i,d+1)-c);
	}
	for(int i=a+c+1;i<=2*b;i++)
	{
	    if(i<=c)continue;
	    ans+=(c-b+1)*(min(i,d+1)-c);
	}
	for(int i=2*b+1;i<=b+c;i++)
	{
	    if(i<=c)continue;
	    ans+=(b+c+1-i)*(min(i,d+1)-c);
	}
	printf("%lld\n",ans);
	return 0;
}