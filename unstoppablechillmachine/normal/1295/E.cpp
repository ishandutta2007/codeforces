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

const int N = 2e5 + 10;
int t[4 * N], f[4 * N], a[N], x[N], vl[N];

inline void push(int v) {
	t[2 * v] += f[v];
	t[2 * v + 1] += f[v];
	f[2 * v] += f[v];
	f[2 * v + 1] += f[v];
	f[v] = 0;
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = vl[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int a, int b, int delta) {
	if (l > b || r < a) {
		return;
	}
	if (l >= a && r <= b) {
		t[v] += delta;
		f[v] += delta;
		return;
	}
	push(v);
	int mid = (l + r) / 2;
	update(2 * v, l, mid, a, b, delta);
	update(2 * v + 1, mid + 1, r, a, b, delta);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for (int i = 1; i <= n; i++) {
		cin >> x[a[i]];
	}
	for (int i = 1; i <= n; i++) {
		vl[i] = vl[i - 1] + x[i];
	}
	build(1, 0, n);
	int ans = 1e18;
	for (int i = 1; i < n; i++) {
		update(1, 0, n, a[i], n, -x[a[i]]);
		update(1, 0, n, 0, a[i] - 1, x[a[i]]);
		ans = min(ans, t[1]);
		//cout << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
}