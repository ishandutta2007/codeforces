#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],inv[max_n];
const int mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt0=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			cnt0+=!a[i];
		}
		int cnt1=0;
		for(int i=1;i<=cnt0;++i)
			cnt1+=a[i];
		inv[1]=1;
		for(int i=2;i<=cnt1;++i)
			inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		int ans=0;
		for(int i=1;i<=cnt1;++i)
			ans=(ans+1ll*inv[i]*inv[i])%mod;
		ans=n*(n-1ll)/2%mod*ans%mod;
		printf("%d\n",ans);
	}
	return 0;
}