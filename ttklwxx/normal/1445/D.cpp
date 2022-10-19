#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define mod 998244353
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
int a[500005],ans=0,jc[500005];
bool bi(int x,int y)
{
	return x>y;
}
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		n=1LL*n*n%mod;
		k>>=1;
	}
	return ans;
}
signed main()
{
	int n,ans=0;
	n=read();
	for(int i=1;i<=2*n;i++)a[i]=read();
	sort(a+1,a+2*n+1);
	jc[0]=1;
	for(int i=1;i<=2*n;i++)jc[i]=1LL*i*jc[i-1]%mod;
	for(int i=n+1;i<=2*n;i++)
	{
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)ans-=a[i];
	ans%=mod;
	ans=1LL*ans*jc[2*n]%mod*ksm(jc[n],mod-2)%mod*ksm(jc[n],mod-2)%mod;
	printf("%lld\n",ans);
	return 0;
}