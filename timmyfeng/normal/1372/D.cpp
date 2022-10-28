#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<long long> pre_sum(n);
	vector<long long> suf_sum(n);

	for (int i = 0; i < n; ++i) {
		if (i - 2 >= 0) {
			pre_sum[i] = pre_sum[i - 2];
		}
		pre_sum[i] += a[i];
	}
	
	for (int i = n - 1; i >= 0; --i) {
		if (i + 2 < n) {
			suf_sum[i] += suf_sum[i + 2];
		}
		suf_sum[i] += a[i];
	}

	long long ans = a[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, pre_sum[i - 1] + suf_sum[i]);
	}
	cout << ans << "\n";
}