#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ll sum = 0;
		ll xor_sum = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			sum += a;
			xor_sum ^= a;
		}

		cout << 2 << "\n";
		cout << xor_sum << " " << sum + xor_sum << "\n";
	}
}