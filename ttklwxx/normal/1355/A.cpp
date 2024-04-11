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
int f(int n)
{
	if(n==0)return 0;
	int minn=9,maxn=0,tn=n;
	while(n!=0)
	{
		minn=min(minn,n%10);
		maxn=max(maxn,n%10);
		n/=10;
	}
	return tn+minn*maxn;
}
signed main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int j=1;j<=k-1;j++)
		{
			if(f(n)==n)break;
			n=f(n);
		}
		printf("%lld\n",n);
	}
	return 0;
}