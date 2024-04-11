#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

bool spec[MX];
vector<pair<char, int>> chd[MX];
int pos[MX], dp[MX], st[MX * 4], la[MX * 4], dep, n;

void push(int v) {
	st[v * 2] += la[v];
	la[v * 2] += la[v];
	st[v * 2 + 1] += la[v];
	la[v * 2 + 1] += la[v];
	la[v] = 0;
}

int qry(int a, int b, int v = 1, int l = 0, int r = n) {
	if (b < l || r < a)
		return 1e9;
	if (a <= l && r <= b)
		return st[v];
	push(v);
	int m = (l + r) / 2;
	return min(qry(a, b, v * 2, l, m), qry(a, b, v * 2 + 1, m + 1, r));
}

void upd(int a, int val, int v = 1, int l = 0, int r = n) {
	if (l == r) {
		st[v] = val;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (a <= m) {
		upd(a, val, v * 2, l, m);
	} else {
		upd(a, val, v * 2 + 1, m + 1, r);
	}
	st[v] = min(st[v * 2], st[v * 2 + 1]);
}

void updr(int a, int b, int val, int v = 1, int l = 0, int r = n) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		st[v] += val;
		la[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		updr(a, b, val, v * 2, l, m);
		updr(a, b, val, v * 2 + 1, m + 1, r);
		st[v] = min(st[v * 2], st[v * 2 + 1]);
	}
}

void dfs(int u) {
	if (spec[u]) {
		dp[u] = min(dp[u], qry(0, dep - 1));
		updr(0, dep - 1, 1);
	}
	upd(dep, dp[u] + 1 + spec[u]);
	sort(chd[u].begin(), chd[u].end());
	for (auto [ignore, c] : chd[u]) {
		++dep;
		dp[c] = dp[u] + 1;
		dfs(c);
		--dep;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p;
		char c;
		cin >> p >> c;
		chd[p].emplace_back(c, i);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> pos[i];
		spec[pos[i]] = true;
	}

	dfs(0);
	
	for (int i = 0; i < k; ++i) {
		cout << dp[pos[i]] << ' ';
	}
	cout << '\n';
}