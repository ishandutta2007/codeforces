#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int j = n / 2, ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		while (j < n && a[j] - a[i] < k) {
			++j;
		}
		if (j == n) break;
		++ans;
		++j;
	}
	cout << ans << '\n';
}