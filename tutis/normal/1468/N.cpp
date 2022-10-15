#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*input
7
1 2 3
1 2 3 0 0
2 2 3
1 2 3 1 0
2 2 3
1 2 3 0 1
1 2 5
1 2 3 1 1
0 0 0
0 0 0 0 0
0 0 4
1 0 0 0 0
13 37 42
0 0 0 40 47

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long c[3];
		long long a[5];

		for (auto &&i : c) {
			cin >> i;
		}

		for (auto &&i : a) {
			cin >> i;
		}

		if (a[0] > c[0] or a[1] > c[1] or a[2] > c[2]) {
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < 3; ++i) {
			c[i] -= a[i];
		}

		a[3] -= c[0];

		if (a[3] > 0) {
			c[2] -= a[3];
		}

		a[4] -= c[1];

		if (a[4] > 0) {
			c[2] -= a[4];
		}

		cout << (c[2] < 0 ? "NO\n" : "YES\n");
	}

}