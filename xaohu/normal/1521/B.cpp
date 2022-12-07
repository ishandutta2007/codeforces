#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++) 

using namespace std;

int t, n;
pair<int, int> a[100005];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a + 1, a + n + 1);
		int pos = a[1].second, z = a[1].first;
		auto get = [&](int id) {
			for (int i = z; ; i++) {
				if ((id < n && __gcd(i, a[id + 1].first) > 1) || (id > 1 && __gcd(i, a[id - 1].first) > 1) || (__gcd(i, z) > 1))
					continue;
				return i;
			}
		};
		cout << n - 1 << "\n";
		rep(i, 2, n) {
			int new_number = get(pos);
			cout << pos << " " << a[i].second << " " << new_number << " " << z << "\n";
			a[pos].first = new_number;
			pos = a[i].second;
		}
	}
}