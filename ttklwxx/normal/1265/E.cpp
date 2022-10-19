#include<iostream>
#include<cstdio>
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
int ksm(int n,int k)
{
	if(k==0)return 1;
	if(k==1)return n;
	int nn=ksm(n,k/2);
	if(k%2==0)return 1LL*nn*nn%mod;
	else return 1LL*nn*nn%mod*1LL*n%mod;
}
signed main()
{
	int n,ans=0,x;
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		ans=1LL*(ans+1)*100%mod*1LL*ksm(x,mod-2)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}