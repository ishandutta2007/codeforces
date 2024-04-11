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
	int x0, y0, ax, ay, bx, by, xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	vector<pair<int, int>> a;
	a.pb({x0, y0});
	while (a.back().F <= 2e16 && a.back().S <= 2e16) {
		a.pb({a.back().F * ax + bx, a.back().S * ay + by});
	}
	int ans = 0;
	for (int i = 0; i < SZ(a); i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = i; k < SZ(a); k++) {
				int kek = abs(xs - a[i].F) + abs(a[i].F - a[j].F) + abs(a[j].F - a[k].F) + 
				abs(ys - a[i].S) + abs(a[i].S - a[j].S) + abs(a[j].S - a[k].S);
				if (kek <= t) {
					ans = max(ans, k - j + 1);
				}
				kek = abs(xs - a[i].F) + abs(a[i].F - a[k].F) + abs(a[j].F - a[k].F) + 
				abs(ys - a[i].S) + abs(a[i].S - a[k].S) + abs(a[j].S - a[k].S);
				if (kek <= t) {
					ans = max(ans, k - j + 1);
				}
			}
		}
	}
	cout << ans << '\n';
}