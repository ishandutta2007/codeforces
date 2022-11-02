#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		long long n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		bool flag = false;
		for (long long s1 = -1; s1 <= 1; s1 += 2) {
			for (int long long s2 = -1; s2 <= 1; s2 += 2) {
				long long x3 = k - s2 * d2 - s1 * 2 * d1;
				if (x3 % 3 == 0) {
					long long a[3] = {x3 / 3, x3 / 3 + s1 * d1, x3 / 3 + s1  * d1 + s2 * d2};
					sort(a, a + 3);
					if (a[0] < 0) {
						continue;
					}
					long long mincost = a[2] - a[0] + a[2] - a[1];
					if (mincost + k > n) {
						continue;
					}
					if ((n - k - mincost) % 3 == 0) {
						flag = true;
					}
				}
			}
		}
		puts(flag ? "yes" : "no");
	}
	return 0;
}