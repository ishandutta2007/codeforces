#include<iostream>
#include<cstdio>
#include<cstring>
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
signed main()
{
	int t,n,m;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=2;i<=n-1;i++)
		{
			if(gcd(n-1,i)==1)
			{
				printf("%lld %lld %lld\n",i,n-1-i,1LL);
				break; 
			}
		}
	} 
	return 0;
}