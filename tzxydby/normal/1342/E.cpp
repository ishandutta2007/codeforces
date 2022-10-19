#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,mod=998244353;
int f[N]={1},inv[N]={1};
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int c(int n,int m)
{
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=200000;i++)
		f[i]=f[i-1]*i%mod,inv[i]=qp(f[i],mod-2);
	int n,k;
	cin>>n>>k;
	if(k>=n)
	{
		cout<<0<<endl;
		return 0;
	}
	if(k==0)
	{
		cout<<f[n]<<endl;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n-k;i++)
	{
		if(i&1)
			ans=(ans-qp(n-k-i,n)*c(n-k,i)%mod+mod)%mod;
		else
			ans=(ans+qp(n-k-i,n)*c(n-k,i)%mod)%mod;
	}
	ans=ans*c(n,n-k)%mod*2%mod;
	cout<<ans<<endl;
	return 0;
}