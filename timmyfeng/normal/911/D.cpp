#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int parity = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i]) {
				parity ^= 1;
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		parity ^= len * (len - 1) / 2 % 2;
		cout << (parity ? "odd" : "even") << '\n';
	}
}