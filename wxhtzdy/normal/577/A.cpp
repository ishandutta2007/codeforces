#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (x % i == 0 && x / i <= n) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}