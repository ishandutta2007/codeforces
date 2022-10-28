#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long a, b, n, m;
		cin >> a >> b >> n >> m;
		cout << (n + m <= a + b && m <= min(a, b) ? "Yes" : "No") << "\n";
	}
}