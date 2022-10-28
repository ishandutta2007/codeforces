#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 2; i < n; ++i) {
		ans += i * (i + 1);
	}
	cout << ans << '\n';
}