#include <iostream>

using namespace std;

long long cnt(long long n, long long k) {
	long long ans = n / k;
	if (n % k != 0) ans++;
	return ans;
}

int main() {
	long long n, k;
	cin >> n >> k;
	long long a = 2 * n, b = 5 * n, c = 8 * n;
	long long ans = 0;
	ans += cnt(a, k);
	ans += cnt(b, k);
	ans += cnt(c, k);
	cout << ans << endl;
	return 0;
}