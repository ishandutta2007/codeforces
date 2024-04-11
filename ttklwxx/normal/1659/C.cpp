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
int p[200005];
int co1[200005];
signed main()
{
	int t,n,a,b,now,minn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a=read();
		b=read();
		p[0]=0;
		for(int i=1;i<=n;i++)p[i]=read();
		co1[0]=0;
		for(int i=1;i<=n;i++)
		{
			co1[i]=co1[i-1]+(a+b)*(p[i]-p[i-1]);
		}
		now=0;
		minn=1121131433448687LL;
		for(int i=n;i>=0;i--)
		{
			minn=min(minn,now+co1[i]);
			if(i==0)break;
			now+=b*(n+1-i)*(p[i]-p[i-1]);
		}
		printf("%lld\n",minn);
	}
}