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
signed main()
{
	int t,n,s0,s1;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		s0=0;
		s1=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]==0)s0++;
			else if(a[i]==1)s1++;
		}
		printf("%lld\n",(1LL<<s0)*s1);
	}
	return 0;
}