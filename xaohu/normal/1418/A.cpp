#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		ll x, y, k;
		cin >> x >> y >> k;
		cout << (k * (1 + y) - 1 + x - 2) / (x - 1) + k << endl;
	}
		
	return 0;
}