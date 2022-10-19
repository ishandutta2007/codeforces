#include<iostream>
#include<cstdio>
#include<map>
#define mod 1000000007
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
map<int,int>ma;
int jc[200005];
int main()
{
	int t,n,tans;
	t=read();
	jc[0]=1;
	for(int i=1;i<=200000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		tans=2147483647;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			ma[a[i]]++;
			tans=(tans&a[i]);
		}
		if(ma[tans]<2)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n",1LL*ma[tans]*(ma[tans]-1)%mod*jc[n-2]%mod);
	}
	return 0;
}