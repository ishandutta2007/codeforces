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
int a[105];
signed main()
{
	int t,n,sl,het=0,maxn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		sl=1;
		het=0;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			while(a[i]%2==0)
			{
				a[i]/=2;
				sl*=2;
			}
			het+=a[i];
			maxn=max(maxn,a[i]);
		}
		printf("%lld\n",het-maxn+maxn*sl);
	}
	return 0;
}