#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int d = max({a, b, c}) - min({a, b, c});
		cout << max(0, d - 2) * 2 << '\n';
	}
}