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
int a[200005];
signed main()
{
	int t,n,x,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		s=0;
		for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
		printf("%lld\n",(s%n)*(n-s%n));
	}
	return 0;
}