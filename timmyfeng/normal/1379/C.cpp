#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<long long> a(m), b(m);
		for (int i = 0; i < m; ++i) {
			cin >> a[i] >> b[i];
		}

		vector<int> ndx(m);
		iota(ndx.begin(), ndx.end(), 0);
		sort(ndx.begin(), ndx.end(), [&a](int i, int j) {
			return a[i] > a[j];
		});
		vector<long long> pre_sum(m + 1);
		for (int i = 0; i < m; ++i) {
			pre_sum[i + 1] = pre_sum[i] + a[ndx[i]];
		}

		long long ans = 0;
		if (n <= m) {
			ans = pre_sum[n];
		}

		for (int i = 0; i < m; ++i) {
			int lb = 0;
			int rb = m;
			while (lb < rb) {
				int mb = (lb + rb) / 2;
				if (a[ndx[mb]] > b[i]) {
					lb = mb + 1;
				} else {
					rb = mb;
				}
			}

			long long res = 0;
			if (n - lb > 0) {
				if (a[i] < b[i]) {
					res = pre_sum[lb] + (n - lb - 1) * b[i] + a[i];
				} else {
					res = pre_sum[lb] + (n - lb) * b[i];
				}
			}
			ans = max(ans, res);
		}
		cout << ans << "\n";
	}
}