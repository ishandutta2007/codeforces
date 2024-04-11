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
    string s;
		cin >> s;
		int n = (int) s.size();
		ll ans = 0;
		for (int i = 0; i < 2; i++) {
			int sz = 0;
			vector<int> svi;
			for (int j = 0; j < n; j++) {
				if (s[j] != '?' && s[j] != (char) ('0' + (i + j % 2) % 2)) {
					if (sz > 0) svi.push_back(sz);
					sz = 0;
				} else {
					sz++;
				}
			}
			if (sz > 0) svi.push_back(sz);
			for (int i : svi) {
				ans += i * 1LL * (i + 1) / 2;
			}
		}
		int sz = 0;
		vector<int> svi;
		for (int j = 0; j < n; j++) {
			if (s[j] != '?') {
				if (sz > 0) svi.push_back(sz);
				sz = 0;
			} else {
				sz++;
			}
		}
		if (sz > 0) svi.push_back(sz);
		for (int i : svi) {
			ans -= i * 1LL * (i + 1) / 2;
		}
		cout << ans << '\n';
  }
}