#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
const int MOD = 1e9 + 7;

struct ST {
	vector<int> t, arr;
	ST(int n) {
		t.resize(4 * n + 10);
	}
	void update(int v, int l, int r, int need, int delta) {
		if (l == r) {
			t[v] += delta;
			return;
		}
		int mid = (l + r) / 2;
		if (need <= mid) {
			update(2 * v, l, mid, need, delta);
		}
		else {
			update(2 * v + 1, mid + 1, r, need, delta);
		}
		t[v] = t[2 * v] + t[2 * v + 1];
	}
	int get_sum(int v, int l, int r, int a, int b) {
		if (l > b || r < a) {
			return 0;
		}
		if (l >= a && r <= b) {
			return t[v];
		}
		int mid = (l + r) / 2;
		return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
	}
};

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<int> srt;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		srt.pb(a[i]);
	}
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	unordered_map<int, int> vl;
	for (int i = 0; i < SZ(srt); i++) {
		vl[srt[i]] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = vl[a[i]];
	}
	ST P(n), S(n);
	int on_suf = 0;
	for (int i = n; i >= 1; i--) {
		on_suf += S.get_sum(1, 1, n, 1, a[i] - 1);
		S.update(1, 1, n, a[i], 1);
	}
	if (on_suf <= k) {
		cout << n * (n - 1) / 2 << '\n';
		exit(0);
	}
	on_suf -= S.get_sum(1, 1, n, 1, a[1] - 1);
	S.update(1, 1, n, a[1], -1);
	int ptr = 2;
	P.update(1, 1, n, a[1], 1);
	int bet = S.get_sum(1, 1, n, 1, a[1] - 1);
	int on_pref = 0;
	while (ptr < n && on_pref + on_suf + bet > k) {
		on_suf -= S.get_sum(1, 1, n, 1, a[ptr] - 1);
		S.update(1, 1, n, a[ptr], -1);
		bet -= P.get_sum(1, 1, n, a[ptr] + 1, n);
		ptr++;
	}
	int ans = 0;
	if (on_pref + on_suf + bet <= k) {
		ans += n - ptr + 1;
	}
	for (int i = 2; i < n; i++) {
		on_pref += P.get_sum(1, 1, n, a[i] + 1, n);
		P.update(1, 1, n, a[i], 1);
		bet += S.get_sum(1, 1, n, 1, a[i] - 1);
		while (ptr < n && on_pref + on_suf + bet > k) {
			on_suf -= S.get_sum(1, 1, n, 1, a[ptr] - 1);
			S.update(1, 1, n, a[ptr], -1);
			bet -= P.get_sum(1, 1, n, a[ptr] + 1, n);
			ptr++;
		}
		if (on_pref + on_suf + bet <= k) {
			ans += n - ptr + 1;
		}
	}
	cout << ans << '\n';
}