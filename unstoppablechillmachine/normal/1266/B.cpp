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
	for (int i = 0; i < T; i++) {
		int sum;
		cin >> sum;
		bool ok = false;
		for (int last = 15; last < 21; last++) {
			if (sum - last >= 0 && (sum - last) % 14 == 0) {
				ok = true;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}	
}