#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int MX = (1 << 20) + 10;
const int N = 25;
bool used[MX];
int calc[MX];
pair<char, int> kek[N];
int a[N], m;

int go(int mask) {
	if (used[mask]) {
		return calc[mask];
	}
	used[mask] = true;
	int id = __builtin_popcount(mask);
	if (id == m) {
		return calc[mask] = 0;
	}
	calc[mask] = -INF;
	for (int i = 0; i < m; i++) {
		if ((mask >> i) & 1) {
			continue;
		}
		int vl = 0;
		if (kek[id].F == 'p') {
			vl += a[i];
		}
		int vl2 = go(mask ^ (1 << i));
		if (kek[id + 1].S == kek[id].S) {
			vl += vl2;
		}
		else {
			vl -= vl2;
		}
		calc[mask] = max(calc[mask], vl);
	}
	return calc[mask];
}

signed main() {
	int n;
	cin >> n;
	vector<int> kk(n);
	for (auto &it : kk) {
		cin >> it;
	}
	sort(all(kk));
	reverse(all(kk));
	cin >> m;
	for (int i = 0; i < m; i++) {
		a[i] = kk[i];
		cin >> kek[i].F >> kek[i].S;
	}
	int vl = go(0);
	cout << (kek[0].S == 1 ? vl : -vl) << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}