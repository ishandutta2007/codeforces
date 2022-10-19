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
	int t,n,m,x=0;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		m=read();
		x=0;
		for(int j=1;j<=9;j++)x+=(m*j)%10;
		x=x*(n/(10*m));
		for(int j=1;j<=(n/m)%10;j++)x+=(m*j)%10;
		printf("%lld\n",x);
	}
	return 0;
}