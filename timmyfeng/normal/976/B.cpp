#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	ll k;
	cin >> n >> m >> k;
	if (k < n) {
		cout << k + 1 << ' ' << 1 << '\n';
		return 0;
	}
	k -= n;
	int row = k / (m - 1);
	if (row % 2) {
		cout << n - row << ' ' << m - (k % (m - 1)) << '\n';
	} else {
		cout << n - row << ' ' << 2 + (k % (m - 1)) << '\n';
	}
}