#include<iostream>
#include<cstdio>
#include<algorithm>
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
int d[200005]; 
signed main()
{
	int t,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)d[i]=read();
		sort(d+1,d+n+1);
		ans=0;
		for(int i=1;i<=n;i++)ans+=d[i]*(n-i*2+1);
		printf("%lld\n",d[n]+ans);
	}
	return 0;
}