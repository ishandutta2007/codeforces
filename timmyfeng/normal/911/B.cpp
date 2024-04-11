#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	cin >> n >> a >> b;

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = max(ans, min(a / i, b / (n - i)));
	}
	cout << ans << '\n';
}