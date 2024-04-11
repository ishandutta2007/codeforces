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

const int maxn = 4010;

long long f[maxn];
long long c[maxn][maxn];

const long long p = (int)1e9 + 7;

long long C(int n, int k) {
	if (c[n][k] == -1) {
		if (k == n || k == 0) {
			c[n][k] = 1;
		} else {
			c[n][k] = C(n - 1, k) + C(n - 1, k - 1);
			c[n][k] %= p;
		}
	}

	return c[n][k];
}

int main() {
	memset(c, -1, sizeof c);
	f[1] = 1;
	f[0] = 1;

	for (int i = 2; i < maxn; i++) {
		for (int j = 1; j <= i; j++) {
			f[i] += f[i - j] * C(i - 1, j - 1);
			f[i] %= p;
		}
	}

	int n;

	cin >> n;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += C(n, i) * f[n - i];
		ans %= p;
	}

	cout << ans << endl;

	return 0;
}