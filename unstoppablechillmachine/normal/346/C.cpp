#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

signed main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	int f, t;
	cin >> f >> t;
	int ans = 0;
	while (f != t) {
		int mx = 1;
		bool ok = false;
		for (auto it : a) {
			if (f % it <= f - t) {
				ok = true;
				mx = max(mx, f % it);
			}
		}
		f -= mx;
		if (!a.empty() && a.back() > f) {
			if (t == 0) {
				cout << ans + 2 << '\n';
				exit(0);
			}
			else {
				while (!a.empty() && a.back() > f) {
					a.pop_back();
				}
			}
		}
		ans++;
		if (!ok) {
			break;
		}
	}	
	cout << ans + f - t << '\n';
}