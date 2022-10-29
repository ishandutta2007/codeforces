#include <iostream>
#define int long long
using namespace std;
signed main() {
	int n,l,r;
	cin >> n >> l >> r;
	int ans=0;
	ans=(1<<l);
	--ans;
	ans+=(n-l);
	cout << ans << " ";
	ans=0;
	ans=(1<<r);
	--ans;
	ans+=(1<<r-1)*(n-r);
	cout << ans;
	return 0;
}