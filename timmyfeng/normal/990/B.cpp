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

	int j = 0, ans = n;
	for (int i = 0; i < n; ++i) {
		while (j < n && a[j] == a[i]) {
			++j;
		}
		if (j < n && a[j] - a[i] <= k) {
			--ans;
		}
	}
	cout << ans << '\n';
}