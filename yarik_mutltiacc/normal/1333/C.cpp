#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define int long long
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


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi a{0};
	for(int t, i = 0; i < n; i++) cin >> t, a.pb(t+a.back());
	map<int, int> lst;
	int b = 0;
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		if(lst.count(a[i]))
		b = max(b, lst[a[i]]+1);
		ans += i-b;
		lst[a[i]] = i;
	}
	cout << ans;
	return 0;
}