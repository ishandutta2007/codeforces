#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	string s;
	cin >> n >> s;
	vector<int> a(n + 1), b(n + 1);
	for (int i = n - 1; ~i; --i) {
		a[i] = a[i + 1] + (s[i] == 'A');
		b[i] = b[i + 1] + (s[i] == 'B');
	}
	ll ans = 0;
	int x = -1, y = -1;
	for (int i = n - 1; ~i; --i) {
		if (s[i] == 'A') {
			if (~x) {
				ans += a[x] + max(0, b[x] - (b[i] == b[x]));
			}
			x = i;
		} else {
			if (~y) {
				ans += b[y] + max(0, a[y] - (a[i] == a[y]));
			}
			y = i;
		}
	}
	cout << ans << '\n';
}