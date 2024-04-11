#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define vi vector<int>

using namespace std;

const int P = 1e9 + 7;

int t, n;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> m;
		int x = (1ll << 31) - 1;
		FOR(i, n) {
			int a;
			cin >> a;
			m[a]++;
			x &= a;
		}
		long long ans = 1ll * m[x] * (m[x] - 1) % P;
		rep(i, 1, n - 2)
			ans = ans * i % P;
		cout << ans << "\n";
	}
	return 0;
}