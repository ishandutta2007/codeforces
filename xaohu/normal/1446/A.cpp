#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int T, n;
ll w, a[222000];

void solve() {
	cin >> n >> w;
	rep(i, 1, n) cin >> a[i];
	ll s = 0;
	vector<int> ans;
	rep(i, 1, n) {
		if (w < a[i]) continue;
		if (w <= 2 * a[i]) {
			cout << 1 << endl << i << endl;
			return;
		}
		s += a[i];
		ans.push_back(i);
		if (w <= 2 * s) {
			cout << ans.size() << endl;
			for (auto e : ans)
				cout << e << " ";
			cout << endl;
			return;
		}
	}
	cout << "-1\n";
}	
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}