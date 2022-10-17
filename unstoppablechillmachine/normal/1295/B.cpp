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
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		int all = 0;
		for (auto it : s) {
			if (it == '0') {
				all++;
			}
			else {
				all--;
			}
		}
		int cur = 0, ans = 0;
		if (x == 0) {
			ans++;
		}
		bool bb = false;
		for (auto it : s) {
			if (it == '0') {
				cur++;
			}
			else {
				cur--;
			}
			if (all == 0) {
				if (cur == x) {
					bb = true;
					break;
				}
			}
			else {
				int kek = x - cur;
				if (abs(kek) % abs(all) == 0 && kek * 1ll * all >= 0) {
					ans++;
				}
			}
		}
		if (bb) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}	
}