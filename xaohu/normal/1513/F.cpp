#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define vi vector<int>

using namespace std;

int n, a[666000];
long long ans;
tuple<int, int, int> t[666000];

int main() {
	cin >> n;
	FOR(i, n) cin >> a[i];
	FOR(i, n) {
		int b, c = 0;
		cin >> b;
		if (a[i] > b) {
			swap(a[i], b);
			c = 1;
		}
		t[i] = {a[i], b, c};	
		ans += b - a[i];
	}
	sort(t, t + n);
	int res = 0, d[2]{};
	FOR(i, n) {
		auto [l, r, q] = t[i];
		res = max(res, min(r, d[!q]) - l);
		d[q] = max(d[q], r);
	}
	cout << ans - 2 * res << "\n";
	return 0;
}