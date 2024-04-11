#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n = min(a, b), m = max(a, b);
	int ans = 0;
	ans += n * (m / 2);
	if (m % 2 == 1) {
		ans += n / 2;
	}
	cout << ans;
}