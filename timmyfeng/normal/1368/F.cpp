#include <bits/stdc++.h> 
using namespace std;

int lamp[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k = 1;
	int r = 0;
	for (int i = 2; i <= n; ++i) {
		int res = n - i - (n + i - 1) / i + 1;
		if (res > r) {
			r = res;
			k = i;
		}
	}

	while (count(lamp, lamp + n, true) < r) {
		cout << k;
		for (int i = 0, j = 0; j < k; ++i) {
			if (i % k && !lamp[i]) {
				cout << " " << i + 1;
				lamp[i] = true;
				++j;
			}
		}
		cout << endl;

		int ndx;
		cin >> ndx;
		for (int i = 0; i < k; ++i) {
			lamp[(ndx - 1 + i) % n] = false;
		}
	}
	cout << 0 << endl;
}