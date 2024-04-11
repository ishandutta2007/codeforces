#include <iostream>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	long long n, k, M, D;
	cin >> n >> k >> M >> D;
	long long res = 0;
	for (long long d = 1; d <= D + 1; d++) {
		// n - 1  < (k * (d - 1))
		// (n - 1) / k < d - 1
		long long x;
		if ((n - 1) / k < d - 1) {
			x = 1;
		} else {
			x = min(M, n / (k * (d - 1) + 1));
			x = max(x, 1LL);
		}
		long long t = n / x;
		long long cnt = (t + k - 1) / k;
		// cerr << cnt << " " << x << endl;
		if (cnt <= D) {
			res = max(res, x * cnt);
		}
	}
	cout << res << endl;
	return 0;
}