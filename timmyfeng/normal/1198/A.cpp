#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, I;
	cin >> n >> I;
	int k = min(20, 8 * I / n);

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	vector<int> pre_sum = {0};
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && a[j] == a[i]) {
			++j;
		}
		pre_sum.push_back(j - i);
	}

	for (int i = 1; i < int(pre_sum.size()); ++i) {
		pre_sum[i] += pre_sum[i - 1];
	}

	int ans = n;
	for (int j = 0; j < int(pre_sum.size()); ++j) {
		int cnt = pre_sum[min(j + (1 << k), int(pre_sum.size()) - 1)] - pre_sum[j];
		ans = min(ans, n - cnt);
	}
	cout << ans << "\n";
}