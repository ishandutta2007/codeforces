#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int A = 0, B = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			A += x;
			B ^= x;
		}
		cout << 2 << '\n' << B << ' ' << A + B << '\n';
	}
}