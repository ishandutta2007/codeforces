// ocajan zad
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
	cin >> tt;
	while (tt--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		auto Get = [&](int x, int y) {
			return lower_bound(a.begin(), a.end(), x + y) - a.begin();
		};
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int x = Get(r - a[i], 1);
			int y = Get(l - a[i], 0);
			ans += x - y;
			if (a[i] * 2 >= l && a[i] * 2 <= r) {
				ans--;
			}
		}
		cout << ans / 2 << '\n';
	}
}