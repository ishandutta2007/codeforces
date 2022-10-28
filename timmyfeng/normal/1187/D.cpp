#include <bits/stdc++.h>
using namespace std;

const int MX = 3e5;

int st[MX * 2], b[MX], n;

void upd(int a, int val) {
	a += n;
	st[a] = val;
	for (a /= 2; a; a /= 2) {
		st[a] = min(st[a * 2], st[a * 2 + 1]);
	}
}

int qry(int a, int b) {
	int res = 1e9;
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res = min(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = min(res, st[b--]);
		}
	}
	return res;
}

void solve() {
	cin >> n;
	vector<queue<int>> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a].push(i);
		st[i + n] = a;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	for (int i = n - 1; i; --i) {
		st[i] = min(st[i * 2], st[i * 2 + 1]);
	}

	for (int i = 0; i < n; ++i) {
		if (pos[b[i]].empty() || qry(0, pos[b[i]].front()) < b[i]) {
			cout << "NO" << '\n';
			return;
		}
		upd(pos[b[i]].front(), 1e9);
		pos[b[i]].pop();
	}
	cout << "YES" << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}