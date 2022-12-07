#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1 << 20;

int n, q, s, d, a[N], p[N], res[N];
tuple<int, int, int> qu[N];
vector<pair<int, int>> e[N];
vector<int> v;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> q >> s >> d;
	s--;

	rep(i, 0, n)
		cin >> a[i];

	rep(i, 0, n) {
		v.push_back(a[i] - d);
		v.push_back(a[i] + d);

		auto add = [&](int x, int y) {
			if (y < 0 || y >= n)
				return;
			int c = 1e9;
			for (auto dir : {-1, 1})
				c = min(c, abs(a[x] + dir * d - a[y]));
			e[c].push_back({x, y});
		};
		
		for (auto dir : {-1, 1}) {
			int p = lower_bound(a, a + n, a[i] - dir * d) - a;
			add(i, p - 1);
			add(i, p);
		}
	}

	rep(i, 0, n) {
		if (i > 0) {
			int p = lower_bound(v.begin(), v.end(), a[i] - d) - v.begin();
			p--;
			if (p >= 0) {
				if (v[p] <= a[i - 1]) {
					e[a[i] - v[p]].push_back({i - 1, i});
				}
			}
		}
		if (i + 1 < n) {
			int p = lower_bound(v.begin(), v.end(), a[i] + d) - v.begin();
			if (p < n) {
				if (a[i + 1] <= v[p]) {
					e[v[p] - a[i]].push_back({i, i + 1});
				}
			}
		}
	}

	rep(i, 0, q) {
		int v, k;
		cin >> v >> k;
		v--;
		qu[i] = {k, v, i};
	}

	sort(qu, qu + q);

	rep(i, 0, n)
		p[i] = i;

	int j = 0;

	rep(i, 0, N) {
		for (auto [a, b] : e[i]) {
			p[find(a)] = find(b);
		}
		while (j < q) {
			auto [k, v, id] = qu[j];
			if (k > i)
				break;
			res[id] = (find(s) == find(v));
			j++;
		}
	}

	rep(i, 0, q)
		cout << (res[i] ? "Yes\n" : "No\n");

	return 0;
}