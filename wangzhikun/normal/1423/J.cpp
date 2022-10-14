/*
 * Author       : YangDavid
 * Created Time : 2020.10.05 21:14:48
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;
void solve() {
	ll x; scanf("%lld", &x);
	ll ans = ((x/2-x/4+1) % MOD) * ((x/4+1)%MOD) % MOD;
	printf("%lld\n", ans);
}
int main() {
	int T; scanf("%d", &T);
	while(T--) solve();

    return 0;
}