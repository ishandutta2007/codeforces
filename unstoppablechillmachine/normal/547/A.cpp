#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
const int MOD = 1e9 + 7;

signed main() {
	int m, h1, a1, x, y, h2, a2, x2, y2;
	cin >> m >> h1 >> a1 >> x >> y >> h2 >> a2 >> x2 >> y2;
	vector<int> used1(m), used2(m), get_vl1(m + 10), get_vl2(m + 10);
	used1[h1] = 1;
	int k1, b1, k2, b2, f1 = -1, f2 = -1;
	int hh1 = h1, hh2 = h2;
	//cout << h1 << ' ';
	for (int i = 2;; i++) {
		h1 = (x * h1 + y) % m;
		//cout << h1 << ' ';
		if (used1[h1]) {
			b1 = used1[h1] - 1;
			k1 = i - used1[h1];
			break;
		}
		used1[h1] = i;
	}
	//cout << used1[a1] << '\n';
	//cout << '\n';
	used2[h2] = 1;
	//cout << h2 << ' ';
	for (int i = 2;; i++) {
		h2 = (x2 * h2 + y2) % m;
		//cout << h2 << ' ';
		if (used2[h2]) {
			b2 = used2[h2] - 1;
			k2 = i - used2[h2];
			break;
		}
		used2[h2] = i;
	}
	//cout << '\n';
	get_vl1[1] = hh1;
	get_vl2[1] = hh2;
	for (int i = 2; i <= m; i++) {
		hh1 = (x * hh1 + y) % m;
		hh2 = (x2 * hh2 + y2) % m;
		get_vl1[i] = hh1;
		get_vl2[i] = hh2;
	}
	//cout << k1 << ' ' << b1 << ' ' << k2 << ' ' << b2 << '\n';
	if (!used1[a1] || !used2[a2]) {
		cout << -1 << '\n';
		exit(0);
	}
	//cout << used1[a1] << ' ' << used2[a2] << '\n';
	if (used1[a1] <= b1) {
		if (get_vl2[used1[a1]] != a2) {
			cout << -1 << '\n';
		}
		else {
			cout << used1[a1] - 1 << '\n';
		}
		exit(0);
	}
	if (used2[a2] <= b2) {
		if (get_vl1[used2[a2]] != a1) {
			cout << -1 << '\n';
		}
		else {
			cout << used2[a2] - 1 << '\n';
		}
		exit(0);
	}
	b1 = used1[a1] - 1;
	b2 = used2[a2] - 1;
	int vl = b2 - b1;
	while (vl < 0) {
		vl += k2;
	}
	vl %= k2;
	for (int x = 0; x < m; x++) {
		if ((k1 * x) % k2 == vl && k1 * x + b1 >= b2) {
			cout << k1 * x + b1 << '\n';
			exit(0);
		} 
	}
	cout << -1 << '\n';
}