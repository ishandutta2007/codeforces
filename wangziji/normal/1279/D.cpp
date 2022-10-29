#include <iostream>
#include <vector>
#define int long long
#define mod 998244353
using namespace std;
vector <int> a[1000005];
int inv[1000005],sum[1000005];
signed main(int argc, char** argv) {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	inv[1]=1;
	for(int i=2;i<=1000000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	int SUM=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
			sum[t]+=inv[k]*inv[n]%mod;
			sum[t]%=mod;
		}
		SUM+=k;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=0,k=a[i].size();
		for(int j=0;j<a[i].size();j++)
			t+=sum[a[i][j]],t%=mod;
		ans+=t,ans%=mod;
	}
	cout << ans%mod*inv[n]%mod;
	return 0;
}