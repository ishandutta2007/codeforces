#include <iostream>

using namespace std;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	long long ans = 0;
	for (int i = 0; i < k; i++) {
		ans += 2 * (n + m) - 4;
		n -= 4;
		m -= 4;
	}
	cout << ans << endl;
	return 0;
}