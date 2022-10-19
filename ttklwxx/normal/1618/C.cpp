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
int a[100005];
int gcd(int x,int y)
{
	if(x==0||y==0)return x+y;
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,n,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1)ans=gcd(ans,a[i]);
		}
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0&&a[i]%ans==0)
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			printf("%lld\n",ans);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)ans=gcd(ans,a[i]);
		}
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1&&a[i]%ans==0)
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			printf("%lld\n",ans);
			continue;
		}
		printf("0\n");
	}
	return 0;
}