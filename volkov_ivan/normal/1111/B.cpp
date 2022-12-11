#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cout.precision(20);
	long double ans = 0;
	long long n, m, k;
	cin >> n >> k >> m;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	long long s = 0;
	for (int i = 0; i < n; i++) s += a[i];
	for (int i = 0; i < n; i++) {
		if (i > m) break;
		long long d = min(k * (n - i), m - i);	
		s += d;
		ans = max(ans, ((long double) s) / (n - i));
		s -= d;
		s -= a[i];
	}
	cout << fixed << ans << endl;
	return 0;
}