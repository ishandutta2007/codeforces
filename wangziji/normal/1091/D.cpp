#include <iostream>
#define int long long
#define mod 998244353
using namespace std;
int jc[1000005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	jc[0]=1;
	for(int i=1;i<=1000000;i++)
		jc[i]=jc[i-1]*i%mod;
	int ans=jc[n],now=1;
	for(int i=n;i>=1;i--)
	{
		now*=i;
		now%=mod;
		ans+=(jc[i-1]-1)*now;
		ans%=mod;
	}
	cout << ans;
	return 0;
}