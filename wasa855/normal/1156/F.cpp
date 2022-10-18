#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int inv[5005];
int a[5005];
int cnt[5005];
int f[5005][5005];
signed main()
{
	int n;
	cin>>n;
	inv[0]=1,inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!cnt[i]) continue;
		f[1][i]=cnt[i]*inv[n]%mod;
	}
	for(int i=2;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			f[i][j]=cnt[j]*sum%mod;
			sum=(sum+f[i-1][j]*inv[n-i+1])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(cnt[j]<2) continue;
			ans=(ans+f[i][j]*inv[n-i]%mod*(cnt[j]-1))%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}