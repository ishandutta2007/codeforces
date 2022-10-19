#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
signed main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ma[a[i]]+=n-i+1;
	}
	for(int i=1;i<=n;i++)
	{
		ma[a[i]]-=n-i+1;
		ans+=i*ma[a[i]];
	}
	printf("%lld\n",ans);
	}
	return 0;
}