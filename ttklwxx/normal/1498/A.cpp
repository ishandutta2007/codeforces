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
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int sum(int n)
{
	int ans=0;
	while(n!=0)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
signed main()
{
	int t,n,x,nn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		while(gcd(n,sum(n))==1)n++;
		printf("%lld\n",n);
	} 
	return 0;
}