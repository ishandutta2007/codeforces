#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 1;

struct Node {
	int pre = 0, suf = 0, sum = 0, res = 0;
} st[MX * 2];

vector<int> pos[MX];
int n;

Node combine(Node a, Node b) {
	return Node{
		max(a.pre, a.sum + b.pre),
		max(b.suf, b.sum + a.suf),
		a.sum + b.sum,
		max({a.res, b.res, a.suf + b.pre})
	};
}

void upd(int a, int val) {
	a += n;
	st[a] = {val, val, val, val};
	for (a /= 2; a; a /= 2) {
		st[a] = combine(st[a * 2], st[a * 2 + 1]);
	}
}

Node qry(int a, int b) {
	Node resl, resr;
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			resl = combine(resl, st[a++]);
		}
		if (b % 2 == 0) {
			resr = combine(st[b--], resr);
		}
	}
	return combine(resl, resr);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> n >> c;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == c) {
			upd(i, -1);
			++cnt;
		} else {
			pos[a].push_back(i);
		}
	}

	int ans = cnt;
	for (int i = 1; i <= MX; ++i) {
		for (auto j : pos[i]) {
			upd(j, 1);
		}
		ans = max(ans, cnt + qry(0, n - 1).res);
		for (auto j : pos[i]) {
			upd(j, 0);
		}
	}
	cout << ans << '\n';
}