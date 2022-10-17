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

const int N = 2e5 + 10;
int a[N], ans;
map<pair<int, int>, int> mp;
void add(int id) {
	a[id]++;
	if (a[id] > 0) {
		ans++;
	}
}

void del(int id) {
	a[id]--;
	if (a[id] >= 0) {
		ans--;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		if (mp.find({s, t}) != mp.end()) {
			add(mp[{s, t}]);
			mp.erase({s, t});
		}
		if (u != 0) {
			mp[{s, t}] = u;
			del(u);
		}
		cout << ans << '\n';
	}
}