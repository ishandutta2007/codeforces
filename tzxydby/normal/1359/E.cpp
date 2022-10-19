#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005,mod=998244353;
int f[N]={1},v[N]={1};
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
	return f[n]*v[m]%mod*v[n-m]%mod;
}
signed main()
{
	for(int i=1;i<=500000;i++)
		f[i]=f[i-1]*i%mod,v[i]=qp(f[i],mod-2);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		if(n/i<k)
			break;
		ans=(ans+c(n/i-1,k-1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}