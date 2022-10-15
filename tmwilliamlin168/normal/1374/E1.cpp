#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

const int mxN=2e5;
int n, k;
vector<ll> v[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	FOR(n) {
		int t, a, b;
		cin >> t >> a >> b;
		v[a*2+b].push_back(t);
	}
	FOR(4) {
		v[i].push_back(0);
		sort(all(v[i]));
		FOR(j, 1, sz(v[i]))
			v[i][j]+=v[i][j-1];
	}
	ll ans=1e18;
	FOR(k+1) {
		if(v[3].size()>i&&v[1].size()>k-i&&v[2].size()>k-i)
			ans=min(ans, v[3][i]+v[1][k-i]+v[2][k-i]);
	}
	cout << (ans>=1e18?-1:ans);
}