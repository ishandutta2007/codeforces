#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
const ll mod = 998244353;
int n;
ll a[maxn];
ll C[maxn][maxn],dp[maxn];
void init()
{
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	init();
	reverse(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;++i)if(a[i]>0)
	{
		for(int j=0;j<=i-(a[i]+1);++j)
		{
			dp[i]+=dp[j]*C[i-j-1][a[i]]%mod;
			dp[i]%=mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=dp[i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}