#include <bits/stdc++.h>
using namespace std;

int n, k;
map <int, int> cnt;

long long P(int x, int y) {
	long long ans = 1;
	while (y--) {
		ans = min(200000LL, ans * x);
	}
	return ans;
}

int main() {
	long long ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int old = x;
		long long y = 1;
		for (int j = 2; j * j <= x; j++) {
			int t = 0;
			while (x % j == 0) {
				t++;
				x /= j;
			}
			t = (k - t % k) % k;
			while (t--) {
				y = min(200000LL, y * j);
			}
		}
		if (x > 1) {
			int t = k - 1;
			while (t--) {
				y = min(200000LL, y * x);
			}
		}
		for (int j = 1; y * P(j, k) <= 100000LL; j++) {
			ans += cnt[y * P(j, k)];
		}
		cnt[old]++;
	}
	cout << ans << endl;
}