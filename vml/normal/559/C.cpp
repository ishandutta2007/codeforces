#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = (int)2e5 + 10;
long long fac[maxn], rfac[maxn];

const long long p = (int)1e9 + 7;

long long my_pow(long long x, int y) {
	if (y == 0) {
		return 1;
	}

	if (y % 2 == 1) {
		return (my_pow(x, y - 1) * x) % p;
	}

	long long t = my_pow(x, y / 2);

	return (t * t) % p;
}

int x[maxn], y[maxn];
int w, h, n;

long long dp[maxn][2];

long long cnk(int a, int b) {
	return ((fac[a] * rfac[b]) % p * rfac[a - b]) % p;
}

long long go(int pos, int cnt) {
	if (dp[pos][cnt] == -1) {
		if (pos == n + 1) {
			if (cnt == 0) {
				dp[pos][cnt] = 1;
			} else {
				dp[pos][cnt] = -1;
			}
		} else {
			dp[pos][cnt] = 0;
			for (int i = 0; i <= n + 1; i++) {
				if (x[i] >= x[pos] && y[i] >= y[pos] && pos != i) {
					int dx = x[i] - x[pos];
					int dy = y[i] - y[pos];
					dp[pos][cnt] += cnk(dx + dy, dx) * go(i, cnt ^ 1);
					dp[pos][cnt] %= p;

					if (dp[pos][cnt] < 0) {
						dp[pos][cnt] += p;
					}
				}
			}
		}
	}

	return dp[pos][cnt];
}

int main() {
	fac[0] = 1;
	rfac[0] = 1;

	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= p;
		rfac[i] = my_pow(fac[i], p - 2);
	}
	
	cin >> w >> h >> n;

	x[0] = 1;
	y[0] = 1;
	x[n + 1] = w;
	y[n + 1] = h;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	memset(dp, -1, sizeof dp);

	cout << go(0, 1) << endl;

	return 0;
}