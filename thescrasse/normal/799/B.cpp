#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x, p[maxn];
set<ll> st[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#if !ONLINE_JUDGE && !EVAL
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (i = 1; i <= n; i++) {
		cin >> a; st[a].insert(p[i]);
	}
	for (i = 1; i <= n; i++) {
		cin >> b; st[b].insert(p[i]);
	}

	cin >> m;
	while (m--) {
		cin >> k;
		if (st[k].empty()) {
			cout << -1 << ' '; continue;
		}

		x = (*st[k].begin());
		st[1].erase(x); st[2].erase(x); st[3].erase(x);
		cout << x << ' ';
	}

	return 0;
}