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
void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	int hm = 0, hp = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[i] && !hm) {cout << "NO\n"; return;}
		if(a[i] < b[i] && !hp) {cout << "NO\n"; return;}
		hm |= a[i] < 0, hp |= a[i] > 0; 
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}