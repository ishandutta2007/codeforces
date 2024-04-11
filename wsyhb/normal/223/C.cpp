#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int max_n=2e3+5;
int a[max_n],b[max_n],inv[max_n],inv_fac[max_n],ans[max_n];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	if(!k)
	{
		for(int i=1;i<=n;++i)
			printf("%d%c",a[i],i<n?' ':'\n');
		return 0;
	}
	inv_fac[0]=1;
	inv[1]=inv_fac[1]=1;
	for(int i=2;i<=n;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
	}
	for(int i=0;i<=n-1;++i)
	{
		int res=1;
		for(int j=i+k-1;j>=k;--j)
			res=1ll*res*j%mod;
		b[i]=1ll*res*inv_fac[i]%mod;
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n-i;++j)
			ans[i+j]=(ans[i+j]+1ll*a[i]*b[j])%mod;
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}