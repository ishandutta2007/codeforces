#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll z[2], ty;
char c;
vector<array<ll, 4>> v[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#if !ONLINE_JUDGE && !EVAL
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif

	cin >> n >> z[0] >> z[1];
	for (i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		if (z[(c == 'D')] < b) continue;
		v[(c == 'D')].pb({b, a, -INF, -INF});
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	for (ty = 0; ty <= 1; ty++) {
		if (!v[ty].empty()) {
			v[ty][0][2] = v[ty][0][1]; v[ty][0][3] = 0;
		}
		for (i = 1; i < v[ty].size(); i++) {
			v[ty][i][2] = max(v[ty][i][1], v[ty][i - 1][2]);
			v[ty][i][3] = i;
		}
	}

	if (!v[0].empty() && !v[1].empty()) res = max(res, v[0].back()[2] + v[1].back()[2]);

	for (ty = 0; ty <= 1; ty++) {
		for (auto [cs, bt, pf, i] : v[ty]) {
			array<ll, 4> o = {z[ty] - cs, INF, INF, INF};
			if (cs <= z[ty] - cs) o = {cs, bt, pf, i};
			auto it = lower_bound(v[ty].begin(), v[ty].end(), o);
			if (it == v[ty].begin()) continue;
			it--;
			res = max(res, bt + (*it)[2]);
		}
	}

	cout << res << nl;

	return 0;
}