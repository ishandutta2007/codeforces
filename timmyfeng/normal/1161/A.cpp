#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> first(n + 1, k);
	vector<int> last(n + 1, -1);
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		if (first[x] == k) {
			first[x] = i;
		}
		last[x] = i;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = max(1, i - 1); j <= i + 1 && j <= n; ++j) {
			ans += (last[j] < first[i]);
		}
	}
	cout << ans << "\n";
}