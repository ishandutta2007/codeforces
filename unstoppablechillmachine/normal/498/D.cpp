#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
const int MX = 60;
int t[4 * N][MX], a[N];

void build(int v, int l, int r) {
	if (l == r) {
		for (int i = 0; i < MX; i++) {
			if (i % a[l] == 0) {
				t[v][i] = 2;
			}
			else {
				t[v][i] = 1;
			}
		}
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	for (int i = 0; i < MX; i++) {
		t[v][i] = t[2 * v][i] + t[2 * v + 1][(i + t[2 * v][i]) % MX];
	}
}

void update(int v, int l, int r, int need) {
	if (l == r) {
		for (int i = 0; i < MX; i++) {
			if (i % a[l] == 0) {
				t[v][i] = 2;
			}
			else {
				t[v][i] = 1;
			}
		}
		return;	
	}
	int mid = (l + r) / 2;
	if (need <= mid) {
		update(2 * v, l, mid, need);
	}
	else {
		update(2 * v + 1, mid + 1, r, need);
	}
	for (int i = 0; i < MX; i++) {
		t[v][i] = t[2 * v][i] + t[2 * v + 1][(i + t[2 * v][i]) % MX];
	}
}

ll curt;

void get(int v, int l, int r, int a, int b) {
	if (l > b || r < a) {
		return;
	}
	if (l >= a && r <= b) {
		curt += t[v][curt % MX];
		return;
	}
	int mid = (l + r) / 2;
	get(2 * v, l, mid, a, b);
	get(2 * v + 1, mid + 1, r, a, b);
}

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char type;
		cin >> type;
		if (type == 'A') {
			int u, v;
			cin >> u >> v;
			v--;
			curt = 0;
			get(1, 1, n, u, v);
			cout << curt << '\n';
		}
		else {
			int pos, vl;
			cin >> pos >> vl;
			a[pos] = vl;
			update(1, 1, n, pos);
		}
	}
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}