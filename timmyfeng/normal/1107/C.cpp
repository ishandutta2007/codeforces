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
	string s;
	cin >> s;
	int j = 0;
	long long ans = 0;
	for (int i = 0; i < n; i = j) {
		while (j < n && s[j] == s[i]) {
			ans += a[j];
			++j;
		}
		sort(a.begin() + i, a.begin() + j);
		for (int u = i; u < j - k; ++u) {
			ans -= a[u];
		}
	}
	cout << ans << '\n';
}