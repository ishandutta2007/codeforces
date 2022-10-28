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
		int odd = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			odd += a % 2;
		}
		if (x == n) {
			cout << (odd % 2 ? "YES" : "NO") << '\n';
		} else {
			int chosen = min(x, odd);
			cout << (chosen && (chosen % 2 || odd < n) ? "YES" : "NO") << '\n';
		}
	}
}