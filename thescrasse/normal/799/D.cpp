#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll h, w, c[maxn], mk, x, y;
__int128 pd;

bool solve(ll n) {
	__int128 i, mk, k, pd;
	vector<__int128> l, r, pl, pr;

	for (i = 1; i <= n / 2; i++) l.pb(c[i]);
	for (i = n / 2 + 1; i <= n; i++) r.pb(c[i]);

	pd = 1;
	for (i = 1; i <= n; i++) pd *= c[i];

	for (mk = 0; mk < (1 << (l.size())); mk++) {
		k = 1;
		for (i = 0; i < l.size(); i++) {
			if ((mk >> i) & 1) k *= l[i];
		}
		pl.pb(k);
	}

	for (mk = 0; mk < (1 << (r.size())); mk++) {
		k = 1;
		for (i = 0; i < r.size(); i++) {
			if ((mk >> i) & 1) k *= r[i];
		}
		pr.pb(k);
	}

	sort(pl.begin(), pl.end());
	sort(pr.begin(), pr.end());

	/* cout << "pd =" _ pd << nl;
	for (auto u : pl) cout << u << ' ';
	cout << nl;
	for (auto u : pr) cout << u << ' ';
	cout << nl; */

	for (auto u : pl) {
		auto it = lower_bound(pr.begin(), pr.end(), (h + u - 1) / u);
		if (it == pr.end()) continue;
		k = u * (*it);
		if (pd / k >= w) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#if !ONLINE_JUDGE && !EVAL
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif

	cin >> a >> b >> x >> y >> n;
	for (i = 1; i <= n; i++) {
		cin >> c[i];
	}

	sort(c + 1, c + n + 1); reverse(c + 1, c + n + 1);

	/* pd = 1;
	for (i = 1; i <= n; i++) {
		if (pd * (__int128)c[i] > (__int128)1e21) {
			n = i - 1; break;
		}
		pd *= c[i];
	} */

	for (i = 0; i <= n; i++) {
		h = (a + x - 1) / x; w = (b + y - 1) / y;
		if (solve(i)) {
			cout << i << nl; return 0;
		}
		h = (a + y - 1) / y; w = (b + x - 1) / x;
		if (solve(i)) {
			cout << i << nl; return 0;
		}
	}

	cout << -1 << nl;

	return 0;
}