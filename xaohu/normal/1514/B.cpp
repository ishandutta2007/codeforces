#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int P = 1e9 + 7;

int t,n,k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int res = 1;
		FOR(i, k)
			res = 1ll * res * n % P;
		cout << res << "\n";
	}
	return 0;
}