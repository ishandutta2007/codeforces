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

signed main() {
	int n;
	cin >> n;
	if ((2 * n * (2 * n + 1) / 2) % 2 == 0) {
		cout << "NO\n";
		exit(0);
	}
	int l = 1, r = n + 1;
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			a[r++] = 2 * i;
			a[l++] = 2 * i - 1;
		}
		else {
			a[l++] = 2 * i;
			a[r++] = 2 * i - 1;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= 2 * n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}