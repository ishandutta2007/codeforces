#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll n, x;
	cin >> n >> x;
	vi a(n);
	for(auto &i : a) cin >> i;
	sort(rall(a));
	ll sm = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		sm += a[i];
		if(sm >= x*(i+1)) ans = i+1;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}