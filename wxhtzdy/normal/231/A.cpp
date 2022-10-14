#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			cnt += x == 1;
		}
		ans += cnt >= 2;
	}
	cout << ans;
}