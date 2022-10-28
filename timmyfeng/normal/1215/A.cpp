#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if (k1 > k2) {
		swap(k1, k2);
		swap(a1, a2);
	}
	cout << max(0, n - (k1 - 1) * a1 - (k2 - 1) * a2) << ' ' << min(n / k1, a1) + min(max(0, n - k1 * a1) / k2, a2) << '\n';
}