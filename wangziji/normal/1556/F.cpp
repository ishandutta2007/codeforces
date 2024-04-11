#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int dp[17000],inv[2000005],f[15][15];
int a[15];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt=0;
/*	for(int i=0;i<(1<<n);i++)
	{
		int S=(1<<n)-1^i;
		for(int j=(S-1)&S;j;j=j-1&S)
		{
			for(int k=(j-1)&j;k;k=k-1&j)
			{
				++cnt;
			}
		}
	}
	cout << cnt;*/
	inv[1]=1;
	for(int i=2;i<=2000000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=a[i]*inv[a[i]+a[j]]%mod;
	for(int i=1;i<(1<<n);i++)
	{
		if(i==(i&-i))
		{
			dp[i]=1;
			continue;
		}
		for(int j=(i-1)&i;j;j=(j-1)&i)
		{
			int qwq=1;
			for(int k=1;k<=n;k++)
			{
				if(((1<<k-1)&i)&&!((1<<k-1)&j))
				{
					for(int l=1;l<=n;l++)
					{
						if((1<<l-1)&j)
						{
							qwq=qwq*f[k][l]%mod;
						}
					}
				}
			}
			dp[i]=(dp[i]+qwq*dp[j])%mod;
		}
		dp[i]=(mod+1-dp[i])%mod;
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		int p=1;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((i&(1<<j-1))&&!(i&(1<<k-1)))
					p=p*f[j][k]%mod;
			}
		}
		int cnt=0;
		for(int j=0;j<n;j++) cnt+=!!((1<<j)&i);
		ans=(ans+dp[i]*cnt%mod*p)%mod;
	}
	cout << ans;
	return 0;
}