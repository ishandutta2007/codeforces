#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using pt = complex<ll>;
#define x real()
#define y imag()

const int MX = 5e5;

int sub[MX], ndx[MX], k;
double cost[MX], ans;
vector<int> adj[MX];
vector<pt> pts;
bool used[MX];

ll dot(pt p, pt q) {
	return (conj(p) * q).x;
}

ll cross(pt p, pt q) {
	return (conj(p) * q).y;
}

double mag(pt p) {
	return sqrt(dot(p, p));
}

bool half(pt p) {
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

int dfs_cost(int u) { 
	int res = 1;
	for (auto c : adj[u]) {
		res += dfs_cost(c);
	}

	int cnt = k - 2 * res + 1;
	cost[u] = mag(pts[u]) * cnt;
	return res;
}

int dfs_sub(int u) {
	int res = used[u];
	for (auto c : adj[u]) {
		res += dfs_sub(c);
	}

	if (used[u]) {
		ans += mag(pts[u]) * (k - 2 * res + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int n;
	cin >> n >> k;

	pts.emplace_back();
	for (int i = 0; i < n; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		if (xi || yi) {
			pts.emplace_back(xi, yi);
		}
	}

	sort(pts.begin() + 1, pts.end(), [](pt a, pt b) {
		return make_tuple(half(a), 0, norm(a)) < make_tuple(half(b), cross(a, b), norm(b));
	});
	pts.emplace_back(0, 0);

	for (int i = 1; i < n; ++i) {
		if (half(pts[i]) == half(pts[i - 1]) && !cross(pts[i], pts[i - 1])) {
			adj[i - 1].push_back(i);
		} else {
			adj[0].push_back(i);
		}
	}

	dfs_cost(0);
	iota(ndx, ndx + n, 0);
	sort(ndx, ndx + n, [&](int a, int b) { return cost[a] > cost[b]; });

	int cnt = 0;
	for (int i = 0; cnt < k; ++i, ++cnt) {
		if (cost[ndx[i]] < 0)
			break;
		used[ndx[i]] = true;
	}

	for (int i = 0; cnt < k; ++i) {
		if (!used[i]) {
			used[i] = true;
			++cnt;
		}
	}

	dfs_sub(0);
	cout << ans << '\n';
}