#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;


int n;
struct aa {
	int a, b;
} a[100];

long long dp[5100][51], dp1[5100][51];

bool cmp(aa x, aa y) {
	if (x.a != y.a)
		return x.a > y.a;
	else
		return x.b > y.b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].a);

	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].b);
	}
	sort(a + 1, a + n + 1, cmp);
	memset(dp, 1, sizeof dp);

	dp[0][0] = 0;
	
	int l = 1;
	while (l <= n) {
		memset(dp1, 1, sizeof dp1);
		int r = l;
		while (r < n && a[r + 1].a == a[l].a)
			r += 1;
		for (int i = 0; i <= r - l + 1; i++) {
			int totb = 0;
			for (int j = l; j <= l + i - 1; j++)
				totb += a[j].b;
			for (int x = 0; x <= 5000; x++)
				for (int y = 0; y <= n; y++)
					if (dp[x][y] <= 1e10 && y >= (r - l + 1) - i) {
						dp1[x + totb][y - ((r - l + 1) - i) + i] = min(dp1[x + totb][y - ((r - l + 1) - i) + i], dp[x][y] + 1LL * a[l].a * i);
					}
		}
		memcpy(dp, dp1, sizeof dp);
		l = r + 1;
	}
	long long ans = 1e15;
	for (int x = 0; x <= 5000; x++)
		for (int y = 0; y <= n; y++)
			if (dp[x][y] <= 1e10) {
				ans = min(ans, (1000 * dp[x][y] + x - 1) / x);
			}
	printf("%I64d\n", ans);
}