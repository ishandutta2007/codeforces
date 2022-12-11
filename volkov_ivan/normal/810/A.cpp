#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	long long ans, k, n, now, sum = 0, x, unusable;
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		cin >> now;
		sum += now;
	}
	ans = ceil(2 * (n * (k - 0.5) - sum));
	x = 0;
	cout << max(ans, x) << endl;
	return 0;
}