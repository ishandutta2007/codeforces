#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int N = 1e5 + 10;
int t[4 * N][2][2];

void build(int v, int l, int r) {
	t[v][0][0] = t[v][0][1] = t[v][1][0] = t[v][1][1] = 1;
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
}

void update(int v, int l, int r, int need, int x) {
	if (l == r) {
		//cout << x << '\n';
		t[v][x][x] ^= 1;
		if (t[v][0][0] && t[v][1][1]) {
			t[v][0][1] = t[v][1][0] = 1;
		}
		else if (t[v][x][x] || t[v][x ^ 1][x ^ 1]) {
			t[v][x ^ 1][x] = t[v][x][x ^ 1] = 0;
		}
		else {
			t[v][0][0] = t[v][1][1] = t[v][1][0] = t[v][1][1] = 0;
		}
		//cout << t[v][0][0] << ' ' << t[v][0][1] << ' ' << t[v][1][0] << ' ' << t[v][1][1] << '\n';
		return;
	}
	int mid = (l + r) / 2;
	if (need <= mid) {
		update(2 * v, l, mid, need, x);
	}
	else {
		update(2 * v + 1, mid + 1, r, need, x);
	}
	t[v][0][0] = t[v][0][1] = t[v][1][0] = t[v][1][1] = 0;
	for (int l = 0; l < 2; l++) {
		for (int r = 0; r < 2; r++) {
			for (int mid = 0; mid < 2; mid++) {
				if (t[2 * v][l][mid] && t[2 * v + 1][mid][r]) {
					t[v][l][r] = 1;
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		update(1, 1, n, y, x);
		cout << (t[1][0][1] ? "Yes\n" : "No\n");
	}
}