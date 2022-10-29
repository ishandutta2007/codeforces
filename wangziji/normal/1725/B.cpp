#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, D;
	cin >> n >> D;
	vector<int> a(n);
	for (int i = 0 ; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {
		long long t = a[r], x = a[r];
		--r;
		while (l <= r && t <= D) {
			t += x;
			++l;
		}
		if (t <= D) break;
		++ans;
	}
	cout << ans << '\n';
}