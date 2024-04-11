#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m {}; cin >> n;
	while(n--) {
		char v; cin >> v;
		m += 1 - 2 * (v - '0');
	}
	cout << abs(m);
}