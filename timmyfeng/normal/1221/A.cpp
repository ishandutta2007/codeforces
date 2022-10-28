#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		while (n--) {
			int a;
			cin >> a;
			if (a <= 2048) {
				sum += a;
			}
		}
		cout << (sum < 2048 ? "NO" : "YES") << '\n';
	}
}