#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> chds;
vector<int> c, a;
bool ok = true;
vector<int> ft;
int n;

void update(int i, int v) {
	for ( ; i <= n; i += i & -i) {
		ft[i] += v;
	}
}

int sum(int i) {
	int ret = 0;
	for ( ; i; i -= i & -i) {
		ret += ft[i];
	}
	return ret;
}

int query(int k) {
	int hi = n;
	int lo = 1;
	while (lo < hi) {
		int mi = (hi + lo) / 2;
		if (sum(mi) < k) {
			lo = mi + 1;
		} else {
			hi = mi;
		}
	}
	return (hi + lo) / 2;
}

int dfs1(int n) {
	int sz = 0;
	for (int v : chds[n]) {
		sz += dfs1(v);
	}
	if (sz < c[n]) {
		ok = false;
	}
	return sz + 1;
}

void dfs2(int n) {
	a[n] = query(c[n] + 1);
	update(a[n], -1);
	for (auto v : chds[n]) {
		dfs2(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	chds.resize(n + 1);
	c.resize(n + 1);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p >> c[i];
		chds[p].push_back(i);
	}

	dfs1(chds[0].back());
	if (!ok) {
		cout << "NO\n";
		return 0;
	}
	ft.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}

	dfs2(chds[0].back());
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
	}
}