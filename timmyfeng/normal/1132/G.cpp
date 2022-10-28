#include <bits/stdc++.h> 
using namespace std;
 
const int MX = 1e6;

int st[MX * 4], la[MX * 4], tin[MX], tout[MX], t, n;
vector<int> chd[MX];

void dfs(int u) {
	tin[u] = ++t;
	for (auto c : chd[u]) {
		dfs(c);
	}
	tout[u] = t;
}

void push(int v) {
	st[v * 2] += la[v];
	la[v * 2] += la[v];
	st[v * 2 + 1] += la[v];
	la[v * 2 + 1] += la[v];
	la[v] = 0;
}

void upd(int a, int b, int val, int v = 1, int l = 1, int r = n) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		st[v] += val;
		la[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> k;
	vector<pair<int, int>> stk;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		while (!stk.empty() && stk.back().first < a) {
			chd[i].push_back(stk.back().second);
			stk.pop_back();
		}
		stk.emplace_back(a, i);
	}

	for (auto [a, i] : stk) {
		dfs(i);
	}

	for (int i = 0; i < n; ++i) {
		upd(tin[i], tout[i], 1);
		if (i >= k - 1) {
			if (i >= k) {
				upd(tin[i - k], tout[i - k], -1);
			}
			cout << st[1] << ' ';
		}
	}
	cout << '\n';
}