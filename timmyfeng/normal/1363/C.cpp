#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			cnt += (u == x || v == x);
		}

		if (cnt <= 1) {
			cout << "Ayush" << '\n';
		} else {
			cout << (n % 2 ? "Ashish" : "Ayush") << '\n';
		}
	}
}