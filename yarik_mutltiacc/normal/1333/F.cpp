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
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<20, mod = (119<<23)+1, lg = 19;
int lp[maxn], inv[maxn];
vi pr;
void sieve() {
	for(int i = 2; i < maxn; i++) {
		if(!lp[i]) lp[i] = i, pr.pb(i);
		for(int j = 0; j < pr.size() && pr[j]*i < maxn && pr[j] <= lp[i]; j++) lp[i*pr[j]] = pr[j];
	}
	inv[0] = inv[1] = 1;
	for(int i = 2; i < maxn; i++) inv[i] = mod - (mod/i) * 1ll * inv[mod%i] % mod;
}
void solve(int n) {
	vi a;
	for(int i = 2; i <= n; i++) a.pb(i/lp[i]);
	sort(all(a));
	for(auto i : a) cout << i << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int n;
	cin >> n;
	solve(n);
	return 0;
}