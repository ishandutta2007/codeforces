#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		int c = b - a;
		int x = min(c / 2, a);
		int ans = x;
		a -= x;
		b -= 3 * x;
		ans += min(a / 2, b / 2);
		cout << ans << '\n';
	}
	return 0;
}