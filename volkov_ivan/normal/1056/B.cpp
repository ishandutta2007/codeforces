#include <iostream>

using namespace std;

const int MAX_M = 1007;
long long cnt[MAX_M];

int main() {
	long long n, m;
	cin >> n >> m;
	long long c = n / m, d = n % m;
	for (long long rest = 1; rest <= m; rest++) {
		long long v = c;
		if (rest <= d) v++;
		cnt[(rest * rest) % m] += v;
	}
	long long ans = 0;
	for (int i = 1; i < m; i++) {
		ans += cnt[i] * cnt[m - i];	
	}
	ans += cnt[0] * cnt[0];
	cout << ans << endl;
	return 0;
}