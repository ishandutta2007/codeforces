#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), ans(n);
		for (auto& i : a) {
			cin >> i;
		}
		int ct = 0;
		for (int i = 2; i * i <= 1000; ++i) {
			bool ok = true;
			for (int j = 2; j * j <= i; ++j) {
				if (i % j == 0) {
					ok = false;
					break;
				}
			}
			if (!ok) continue;
			bool has = false;
			for (int j = 0; j < n; ++j) {
				if (a[j] % i == 0 && !ans[j]) {
					has = true;
					ans[j] = ct + 1;
				}
			}
			ct += has;
		}
		cout << ct << '\n';
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}