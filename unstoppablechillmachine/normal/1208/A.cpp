#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
vector<int> lol[2][2];
signed main() {
	int T;
	cin >> T;
	lol[0][0] = {0};
	lol[1][0] = {1, 1, 0};
	lol[0][1] = {1, 0, 1};
	lol[1][1] = {0, 1, 1};
	while (T--) {
		int a, b, n;
		cin >> a >> b >> n;
		if (n == 0) {
			cout << a << '\n';
			continue;
		}
		if (n == 1) {
			cout << b << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			int x = (a >> i) & 1, y = (b >> i) & 1;
			if (lol[x][y][(n - 2) % SZ(lol[x][y])]) {
				ans |= 1 << i;
			}
		}
		cout << ans << '\n';
	}
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}