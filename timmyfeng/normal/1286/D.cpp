#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using state = tuple<pair<int, int>, int, int>;

const int MX = 1e5;
const int M = (119 << 23) + 1;

vector<int> seg_tree[MX * 4];
int x[MX], v[MX], p[MX], n;
bool ban[MX][4];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return ll(a) * b % M;
}

int mod_pow(int b, int e) {
	int res = 1;
	while (e) {
		if (e % 2) {
			res = mul(res, b);
		}
		b = mul(b, b);
		e /= 2;
	}
	return res;
}

vector<int> combine(const vector<int>& a, const vector<int>& b, int x) {
	vector<int> res(4);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (!ban[x][j * 2 + k]) {
						res[i * 2 + l] = add(res[i * 2 + l], mul(a[i * 2 + j], b[k * 2 + l]));
					}
				}
			}
		}
	}
	return res;
}

void upd(int x, int v = 1, int l = 0, int r = n - 1) {
	if (l == r)
		return;

	int m = (l + r) / 2;
	if (x <= m) {
		upd(x, v * 2, l, m);
	} else {
		upd(x, v * 2 + 1, m + 1, r);
	}

	seg_tree[v] = combine(seg_tree[v * 2], seg_tree[v * 2 + 1], m + 1);
}

void bld(int v, int l, int r) {
	seg_tree[v].resize(4);
	if (l == r) {
		seg_tree[v][3] = mul(p[l], mod_pow(100, M - 2));
		seg_tree[v][0] = sub(1, seg_tree[v][3]);
	} else {
		int m = (l + r) / 2;
		bld(v * 2, l, m);
		bld(v * 2 + 1, m + 1, r);

		seg_tree[v] = combine(seg_tree[v * 2], seg_tree[v * 2 + 1], m + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> v[i] >> p[i];
	}

	vector<state> collision;
	for (int i = 1; i < n; ++i) {
		collision.emplace_back(make_pair(x[i] - x[i - 1], v[i] + v[i - 1]), i, 2);
		if (v[i] < v[i - 1]) {
			collision.emplace_back(make_pair(x[i] - x[i - 1], v[i - 1] - v[i]), i, 3);	
		} else if (v[i - 1] < v[i]) {
			collision.emplace_back(make_pair(x[i] - x[i - 1], v[i] - v[i - 1]), i, 0);
		}
	}

	sort(collision.begin(), collision.end(), [&](state a, state b) {
		return ll(get<0>(a).first) * get<0>(b).second < ll(get<0>(b).first) * get<0>(a).second;
	});

	bld(1, 0, n - 1);

	int ans = 0;
	int pre = 1;
	for (auto [t, x, type] : collision) {
		ban[x][type] = true;
		upd(x - 1);
		upd(x);

		int cur = accumulate(seg_tree[1].begin(), seg_tree[1].end(), 0, add);
		ans = add(ans, mul(sub(pre, cur), mul(t.first, mod_pow(t.second, M - 2))));
		pre = cur;
	}
	cout << ans << "\n";
}