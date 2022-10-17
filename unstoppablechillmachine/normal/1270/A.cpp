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
		int n, a1, a2;
		cin >> n >> a1 >> a2;
		bool ok = false;
		for (int i = 0; i < a1; i++) {
			int x;
			cin >> x;
			if (x == n) {
				ok = true;
			}
		}
		for (int i = 0; i < a2; i++) {
			int x;
			cin >> x;
		}
		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}