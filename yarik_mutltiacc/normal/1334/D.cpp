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
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get(ll pos, ll bl) {
	if(pos%2==0) return bl;
	return bl + (pos+1)/2;
}
void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	ll e = n*(n-1) + 1;
	e = r==e;
	if(e) r--;
	ll bl = 1, st = 1;
	vi ans;
	while(l <= r) {
		while(l > st + 2ll*(n-bl) - 1) {
			st += 2ll*(n-bl);
			bl++;
		}
		ans.pb(get(l-st, bl));
		l++;
	}
	if(e) ans.pb(1);
	for(auto i : ans) cout << i << " "; cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}