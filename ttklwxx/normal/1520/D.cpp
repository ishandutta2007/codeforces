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
map<int,int>ma;
int a[200005];
signed main()
{
	int t,n;
	int ans=0,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			ma[a[i]-i]++;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=ma[a[i]-i]*(ma[a[i]-i]-1)/2;
			ma[a[i]-i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}