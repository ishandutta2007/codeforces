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
int a[200001],b[200001],n;
bool check(int k)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)ans+=b[i];
	}
	if(ans<=k)return true;
	return false;
}
signed main()
{
	int t,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		l=1;
		r=1121131433448687LL;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}