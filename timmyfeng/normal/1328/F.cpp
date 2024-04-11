#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	vector<long long> ps(n + 1);
	for (int i = 1; i <= n; ++i) {
		ps[i] = a[i - 1] + ps[i - 1];
	}

	int j = 0;
   	long long ans = 1e18;
	for (int i = 0; i < n; i = j) {
		for ( ; j < n && a[j] == a[i]; ++j);
		int ct = j - i;
		long long cl = (a[i] - 1) * i - ps[i];
		long long cr = ps[n] - ps[j] - (a[i] + 1) * (n - j);
		if (ct >= k) {
			ans = 0;
			continue;
		}
		if (i + ct >= k) {
			ans = min(ans, cl + k - ct);
		}
		if (n - j + ct >= k) {
			ans = min(ans, cr + k - ct);
		}
		ans = min(ans, cl + cr + k - ct);
	}
	cout << ans << '\n';
}