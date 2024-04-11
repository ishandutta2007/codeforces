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
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (auto &it : a) {
		cin >> it;
	}
	for (auto &it : b) {
		cin >> it;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int c;
		cin >> c;
		c--;
		cout << a[c % n] + b[c % m] << '\n';
	}
}