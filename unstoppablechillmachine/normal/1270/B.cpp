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
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) {
			cin >> it;
		}
		int id = -1;
		for (int i = 0; i + 1 < n; i++) {
			if (abs(a[i] - a[i + 1]) > 1) {
				id = i;
				break;
			}
		}
		if (id == -1) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n" << id + 1 << ' ' << id + 2 << '\n';
		}
	}
}