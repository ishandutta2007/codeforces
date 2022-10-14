#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1e9;
	for (int i = 1; i <= sqrt(n); i++) {
		int j = (n + i - 1) / i;
		ans = min(ans, i + j);
	}
	cout << ans << '\n';
	return 0;
}