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
		int mx = -1e9, diff = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (mx > a) {
				diff = max(mx - a, diff);
			} else {
				mx = a;
			}
		}
		cout << (diff ? 32 - __builtin_clz(diff) : 0) << '\n';
	}
}