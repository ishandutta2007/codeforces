#include<iostream>
#include<cstdio>
#include<cmath>
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
	int t,a,b,sth,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		if(a%b!=0)
		{
			printf("%lld\n",a);
			continue;
		}
		ans=0;
		for(int i=2;i<=sqrt(b);i++)
		{
			if(b%i!=0)continue;
			sth=a;
			while(sth%b==0)sth/=i;
			ans=max(ans,sth);
			while(b%i==0)b/=i;
		}
		if(b!=1)
		{
			sth=a;
			while(sth%b==0)sth/=b;
			ans=max(ans,sth);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}