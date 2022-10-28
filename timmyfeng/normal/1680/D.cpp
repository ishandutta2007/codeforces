#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;

	vector<int> a(n), zeroes(n + 1);
	vector<long long> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		zeroes[i + 1] = zeroes[i] + (a[i] == 0);
		sum[i + 1] = sum[i] + a[i];
	}
 
	long long answer = -2;
	for (int l = 0; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			long long lowl = sum[l] - 1LL * zeroes[l] * k;
			long long highl = sum[l] + 1LL * zeroes[l] * k;

			long long lowm = (sum[r] - sum[l]) - 1LL * (zeroes[r] - zeroes[l]) * k;
			long long highm = (sum[r] - sum[l]) + 1LL * (zeroes[r] - zeroes[l]) * k;

			long long lowr = (sum[r] - sum[n]) - 1LL * (zeroes[n] - zeroes[r]) * k;
			long long highr = (sum[r] - sum[n]) + 1LL * (zeroes[n] - zeroes[r]) * k;

			long long low = max(lowr - highl, lowm);
			long long high = min(highr - lowl, highm);

			if (low <= high) answer = max({answer, abs(low), abs(high)});
		}
	}

	cout << answer + 1 << "\n";
}