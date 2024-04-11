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
const int INF = 1e9 + 10;
int a[N], mx[4 * N];
ll sum[4 * N];

void build(int v, int l, int r) {
	if (l == r) {
		mx[v] = a[l];
		sum[v] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void update(int v, int l, int r, int pos) {
	if (l == r) {
		mx[v] = a[l];
		sum[v] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid) {
		update(2 * v, l, mid, pos);
	}
	else {
		update(2 * v + 1, mid + 1, r, pos);
	}
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

ll get_sum(int v, int l, int r, int a, int b) {
	if (l > b || r < a) {
		return 0;
	}
	if (l >= a && r <= b) {
		return sum[v];
	}
	int mid = (l + r) / 2;
	return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
}

int get_next(int v, int l, int r, int a, int b, int vl) {
	if (l > b || r < a) {
		return INF;
	}
	if (l >= a && r <= b) {
		int cv = v, l2 = l, r2 = r;
		while (l2 != r2) {
			int mid = (l2 + r2) / 2;
			if (mx[cv * 2] >= vl) {
				cv = cv * 2;
				r2 = mid;
			}
			else {
				cv = cv * 2 + 1;
				l2 = mid + 1;
			}
		}
		return (mx[cv] >= vl ? l2 : INF);
	}
	int mid = (l + r) / 2;
	return min(get_next(2 * v, l, mid, a, b, vl), get_next(2 * v + 1, mid + 1, r, a, b, vl));
}

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << get_sum(1, 1, n, l, r) << '\n';
		}
		else if (type == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			while (l <= r) {
				int pos = get_next(1, 1, n, l, r, x);
				if (pos == INF) {
					break;
				}
				a[pos] %= x;
				update(1, 1, n, pos);
				l = pos + 1;
			}
		}
		else {
			int pos, x;
			cin >> pos >> x;
			a[pos] = x;
			update(1, 1, n, pos);
		}
	}
}