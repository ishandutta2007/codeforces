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

const int N = 2e5 + 10;
int t[N], t2[N], ans[N], f[N], n, sz;
void update(int v, int delta) {
	for (; v <= n; v += v & (-v)) {
		t[v] += delta;
	}
}
int get(int v) {
	int res = 0;
	for (; v > 0; v -= v & (-v)) {
		res += t[v];
	}
	return res;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		update(i, i);
		cin >> f[i];
		//cout << f[i] << ' ';
	}
	//cout << '\n';
	for (int i = n; i >= 1; i--) {
		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get(mid) > f[i]) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		ans[i] = r;
		update(r, -r);
	}
	/*for (int i = 1; i <= n; i++) {
		cout << t[i] << ' ';
	}
	cout << '\n';*/
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}