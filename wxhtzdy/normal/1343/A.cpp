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
		int cnt = 3, tr = 4;
		while (n % cnt != 0) {
			cnt += tr;
			tr *= 2;
		}
		cout << n / cnt << endl;
	}
	return 0;
}