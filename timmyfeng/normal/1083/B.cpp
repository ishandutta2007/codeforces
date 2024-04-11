#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;

	int i = 0;
	long long a = 0;
	long long b = 0;
	long long ans = 0;
	long long pre = 0;

	while (k > 0 && i < n) {
		a = 2 * a + s[i] - 'a';
		b = 2 * b + t[i] - 'a';

		long long cnt = b - a + 1 - pre;
		pre = b - a + 1;
		ans += 1LL * (n - i) * min(cnt, 1LL * k);
		k -= cnt;
		++i;
	}
	cout << ans << "\n";
}