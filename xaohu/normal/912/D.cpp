#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

ll n, m, r, k, res;
multiset<pair<ll, pair<ll, ll>>> T;
multiset<pair<ll, ll>> used;

ll calc(ll i, ll j) {
	ll a = min(i, n - r) + 1 - max(i - r + 1, 0ll);
	ll b = min(j, m - r) + 1 - max(j - r + 1, 0ll);
	return a * b;
}

void add(int i, int j) {
	if (0 <= i && i < n && 0 <= j && j < m)
		T.insert({-calc(i, j), {i, j}});
}

int main() {
	cin >> n >> m >> r >> k;
	int x = (n - 1) / 2;
	int y = (m - 1) / 2;
	add(x, y);
	while (k > 0) {
		ll c = -T.begin()->first;;
		int a = T.begin()->second.first;
		int b = T.begin()->second.second;
		T.erase(T.begin());
		if (used.count({a, b}))
			continue;
		k--;
		used.insert({a, b});
		res += c;
		add(a, b - 1);
		add(a, b + 1);
		add(a - 1, b);
		add(a + 1, b);
	}
	double all = (n - r + 1) * (m - r + 1);
	cout << setprecision(20) << res / all << endl;
	return 0;
}