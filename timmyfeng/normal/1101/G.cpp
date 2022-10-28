#include <bits/stdc++.h> 
using namespace std;

const int LOG = 30;

int basis[LOG];

void upd(int ma) {
	for (int i = 0; i < LOG; ++i) {
		if (ma & (1 << i)) {
			if (!basis[i]) {
				basis[i] = ma;
				return;
			}
			ma ^= basis[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int pre = 0;
	while (n--) {
		int a;
		cin >> a;
		pre ^= a;
		upd(pre);
	}
	if (!pre) {
		cout << -1 << '\n';
		return 0;
	}
	cout << LOG - count(basis, basis + LOG, 0) << '\n';
}