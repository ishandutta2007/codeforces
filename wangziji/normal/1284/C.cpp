#include <iostream>
#define int long long
using namespace std;
int jc[1000005];
signed main(int argc, char** argv) {
	int n,mod;
	cin >> n >>  mod;
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%mod;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=jc[i]*jc[n-i+1]%mod*i%mod,ans%=mod;
	cout << ans;
	return 0;
}