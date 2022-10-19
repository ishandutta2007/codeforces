#include<iostream>
#include<cstdio>
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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int a[200005],b[200005];
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read()-i;
		int tr=1;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			while(tr<n&&a[tr+1]>=1-i)tr++;
			ans+=(tr-i+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}