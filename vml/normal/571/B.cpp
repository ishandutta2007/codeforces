#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>
 
using namespace std;

const int maxn = (int)3e5 + 10;

long long v[maxn];
long long dp[5010][5010];
int d;

long long go(int a, int b, int pos) {
	if (dp[a][b] == -1) {
		if (a == 0 && b == 0) {
			dp[a][b] = 0;
		} else {
			dp[a][b] = (long long)1e18;
			if (a != 0) {
				dp[a][b] = go(a - 1, b, pos + d) + (v[pos + d - 1] - v[pos]);
			}

			if (b != 0) {
				dp[a][b] = min(dp[a][b], go(a, b - 1, pos + d - 1) + (v[pos + d - 2] - v[pos]));
			}
		}
	}

	return dp[a][b];
}

int main() {
	memset(dp, -1, sizeof dp);
	int n, k;

	scanf("%d %d", &n, &k);

	d = (n + k - 1) / k;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);
	}

	sort(v, v + n);

	int a = (n - 1) % k + 1;

	int b = k - a;

	if (d * a + (d - 1) * b != n) {
		throw 1;
	}

	cout << go(a, b, 0) << endl;

	return 0;
}