#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());
		int sol = -1;
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			if (i) {
				sum += a[i - 1];
			}
			int tmp1 = p - sum;
			int tmp2 = i;
			for (int j = i + k - 1; j < n && a[j] <= tmp1; j += k) {
				tmp1 -= a[j];
				tmp2 += k;
			}
			if (tmp2 <= sol || tmp1 < 0) break;
			sol = tmp2;
		}
		cout << sol << "\n";
	}
}