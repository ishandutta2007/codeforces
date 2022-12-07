#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int n, t, cnt[1 << 20], memo[1 << 20];

int query(int node, int l, int r) {
	if (memo[node])
		return cnt[node];
	memo[node] = 1;
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	x = (r - l + 1) - x;
	return cnt[node] = x;
}	

void solve(int l, int r, int k, int v = 1) {
	cnt[v] = query(v, l, r);
	if (l == r) {
		cout << "! " << l << endl;
		cnt[v]--;
		return;
	}
	int m = (l + r) / 2;
	cnt[2 * v] = query(2 * v, l, m);
	memo[2 * v + 1] = 1;
	cnt[2 * v + 1] = cnt[v] - cnt[2 * v];
	if (k <= cnt[2 * v]) {
		solve(l, m, k, 2 * v);
	}
	else {
		solve(m + 1, r, k - cnt[2 * v], 2 * v + 1);
	}
	cnt[v]--;
}

int main() {
	cin >> n >> t;
	while (t--) {
		int k;
		cin >> k;
		solve(1, n, k);
	}
	return 0;
}