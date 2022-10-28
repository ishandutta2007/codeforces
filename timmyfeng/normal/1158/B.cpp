#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k == 1) {
		cout << '1' << string(n - 1, '0') << "\n";
		return 0;
	}

	int period = (n - k) / 2 + 1;
	for (int i = 0; i < n; ++i) {
		cout << (i % period == 0 || (i % period == period - 1 && period != 2));
	}
	cout << "\n";
}