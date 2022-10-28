#include <bits/stdc++.h> 
using namespace std;

const int MX = 300;
const int MXC = 1e3;
const int MXQ = 2e6;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

vector<tuple<int, int, int>> req[MXQ + 1], rem[MXQ + 1];
int par[MX * MX], sz[MX * MX], ans[MXQ + 2], mat[MX][MX];

int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q, mxc = 0;
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		if (mat[x][y] == c)
			continue;
		req[c].emplace_back(x, y, i);
		rem[mat[x][y]].emplace_back(x, y, i);
		mat[x][y] = c;
		mxc = c;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			rem[mat[i][j]].emplace_back(i, j, q + 1);
		}
	}

	auto toint = [&](int x, int y) {
		return x * m + y;
	};

	auto add = [&](int x, int y) {
		int res = 1;
		par[toint(x, y)] = toint(x, y);
		for (int j = 0; j < 4; ++j) {
			int nx = x + DX[j];
			int ny = y + DY[j];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && par[toint(nx, ny)] != -1) {
				res -= unite(toint(x, y), toint(nx, ny));
			}
		}
		return res;
	};

	ans[0] = 1;
	memset(par, -1, sizeof par);
	for (int k = 0; k <= mxc; ++k) {
		for (auto [x, y, t] : req[k]) {
			ans[t] += add(x, y);
		}
		for (auto [x, y, ignore] : req[k]) {
			par[toint(x, y)] = -1;
			sz[toint(x, y)] = 0;
		}

		reverse(rem[k].begin(), rem[k].end());
		for (auto [x, y, t] : rem[k]) {
			ans[t] -= add(x, y);
		}
		for (auto [x, y, ignore] : rem[k]) {
			par[toint(x, y)] = -1;
			sz[toint(x, y)] = 0;
		}
	}

	for (int i = 1; i <= q; ++i) {
		ans[i] += ans[i - 1];
		cout << ans[i] << '\n';
	}
}