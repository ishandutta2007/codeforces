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
int a[200005];
bool check(int n,int k,int h)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=min(a[i+1]-a[i],k);
		if(ans>=h)return true;
	}
	return false;
}
signed main()
{
	int t,n,h,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		h=read();
		for(int i=1;i<=n;i++)a[i]=read();
		a[n+1]=2e18;
		l=1;
		r=2e18;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(n,mid,h))r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",l);
	} 
	return 0;
}