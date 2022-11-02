#include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>

using namespace std;

int n, k1, k2, a[3100], b[3100], c[3100];

int main() {
	scanf("%d%d%d", &n, &k1, &k2);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		c[i] = abs(b[i] - a[i]);
	int k = k1 + k2;
	while (k--) {
		int t = 1;
		for (int i = 2; i <= n; i++)
			if (c[i] > c[t])
				t = i;
		if (c[t] == 0)
			c[t] += 1;
		else
			c[t] -= 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1LL * c[i] * c[i];
	// printf("%I64d\n", ans);
	cout << ans << endl;
}