#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		int d = abs(b - a);
		int ans = d / 5;
		if (d % 5) {
			if (d % 5 == 3 || d % 5 == 4) {
				ans += 2;
			} else {
				++ans;
			}
		}
		cout << ans << '\n';
	}
}