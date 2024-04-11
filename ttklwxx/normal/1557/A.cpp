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
	int t,n,het,maxn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		het=0;
		maxn=-1000000000;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			maxn=max(maxn,a[i]);
			het+=a[i];
		}
		printf("%.9lf\n",(double)maxn+(double)(het-maxn)/(n-1));
	}
	return 0;
}