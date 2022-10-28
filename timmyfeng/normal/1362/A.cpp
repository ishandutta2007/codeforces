#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}

		ll diff = b / a;
		if (a * diff != b || diff & (diff - 1)) {
			cout << -1 << '\n';
		} else {
			cout << (__builtin_ctzll(diff) + 2) / 3 << '\n';
		}
	}
}