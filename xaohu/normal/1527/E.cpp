#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 1 << 16;
const long long INF = 1e18;

struct tree {
	long long t[2 * N], tag[2 * N];
	tree() {
		fill(t, t + 2 * N, INF);
		fill(tag, tag + 2 * N, 0);
	}
	void add(int v, long long x) {
		t[v] += x;
		tag[v] += x;
	}
	void push(int v) {
		add(2 * v, tag[v]);
		add(2 * v + 1, tag[v]);
		tag[v] = 0;
	}
	void upd(int x, int y, long long z, int v = 1, int l = 0, int r = N - 1) {
		if (y < l || r < x) return;
		if (x <= l && r <= y) {
			add(v, z);
			return;
		}
		push(v);
		int m = (l + r) / 2;
		upd(x, y, z, 2 * v, l, m);
		upd(x, y, z, 2 * v + 1, m + 1, r);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}	
};

int n, k, a[N], prv[N];
long long dp1[N], dp2[N];
map<int, int> lst;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> a[i];
		prv[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	fill(dp1, dp1 + N, INF);
	dp1[0] = 0;
	rep(j, 1, k) {
		dp2[0] = INF;
		tree T;
		rep(i, 1, n) {
			T.upd(i, i, -INF + dp1[i - 1]);
			if (prv[i])
				T.upd(1, prv[i], i - prv[i]);
			dp2[i] = T.t[1];
		}
		swap(dp1, dp2);
	}
	cout << dp1[n] << "\n";
	return 0;
}