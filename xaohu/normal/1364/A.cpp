#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int t, n, m; 
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int all = 0, ans = -1;
		rep(i, 1, n) {
			int x;
			cin >> x;
			all = (all + x) % m;
			if (all)
				ans = max(ans, max(i, n - i));
		}
		if (all) ans = n;
		cout << ans << "\n";
	}
	return 0;
}