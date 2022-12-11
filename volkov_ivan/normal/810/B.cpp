#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(long long a, long long b) {
	return (a > b);
}

int main() {
	int n, f;
	cin >> n >> f;
	long long ans = 0, k, l, a[n];
	for (int i = 0; i < n; i ++) {
		cin >> k >> l;
		ans += min(k, l);
		a[i] = min(2 * k, l) - min(k, l);
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < f; i ++) {
		ans += a[i];
	}
	cout << ans;
	return 0;
}