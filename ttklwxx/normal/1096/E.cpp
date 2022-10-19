#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define mod 998244353
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
int n,m,k;
int jc[10000005],njc[10000005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
int c(int n,int m)
{
	return 1LL*jc[n]*njc[m]%mod*njc[n-m]%mod;
}
signed main()
{
	jc[0]=1;
	for(int i=1;i<=10000000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[10000000]=ksm(jc[10000000],mod-2);
	for(int i=9999999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	n=read();
	m=read();
	k=read();
	int ans=0,sth=c(m-k+n-1,n-1);
	for(int i=n;i>=1;i--)
	{
		if(m<i*k)continue;
		if(i%2==0)ans=(ans+mod-1LL*c(n,i)*c(m-i*k+n-1,n-1)%mod)%mod;
		else ans=(ans+1LL*c(n,i)*c(m-i*k+n-1,n-1)%mod)%mod;
		//printf("%lld %lld\n",i,a[i]);
	}
	//printf("%lld %lld\n",ans*2%mod,sth);
	ans=1LL*ans*ksm(n,mod-2)%mod;
	printf("%lld\n",1LL*ans*ksm(sth,mod-2)%mod);
	return 0;
}