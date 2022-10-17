#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 5e5 + 10;
const int INF = 1e9 + 10;
pair<int, int> t[4 * N];
int L[N], R[N], a[N], n;

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = {a[l], l};
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int need) {
	if (l == r) {
		t[v] = {INF, 0};
		return;
	}
	int mid = (l + r) / 2;
	if (need <= mid) {
		update(2 * v, l, mid, need);
	}
	else {
		update(2 * v + 1, mid + 1, r, need);
	}
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

pair<int, int> get(int v, int l, int r, int a, int b) {
	if (l > b || r < a) {
		return {INF, 0};
	}
	if (l >= a && r <= b) {
		return t[v];
	}
	int mid = (l + r) / 2;
	return min(get(2 * v, l, mid, a, b), get(2 * v + 1, mid + 1, r, a, b));
}

int solve(int l, int r) {
	// /cout << l << ' ' << r << '\n';
	pair<int, int> k1 = get(1, 1, n, l, r), k2 = get(1, 1, n, l + 1, r - 1);
	if (k2.F == INF) {
		return 0;
	}
	//cout << k1.F << ' ' << k1.S << '\n';
	if (k2.F == k1.F) {
		int A = L[k2.S], B = R[k2.S];
		int vl = min(a[A], a[B]);
		update(1, 1, n, k2.S);
		L[B] = A;
		R[A] = B;
		return vl + solve(l, r);
	}
	if (a[l] == k1.F) {
		return k1.F + solve(R[l], r);
	}
	return k1.F + solve(l, L[r]);
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		L[i] = i - 1;
		R[i] = i + 1;
	}	
	build(1, 1, n);
	cout << solve(1, n) << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}