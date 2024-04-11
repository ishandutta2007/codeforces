//#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = 2000;

int dp[maxn][maxn];

pair <int, int> t[maxn];
int h;
int n;

int go(int pos, int x, int last) {
	int cnt = h - t[pos].first - last;

	while (cnt > 0) {
		x *= 2;
		cnt--;

		if (x > n) {
			x = n;
			break;
		}
	}

	if (x > n) {
		x = n;
	}

	if (dp[pos][x] == -1) {
		if (pos == n) {
			dp[pos][x] = 0;
		} else {
			if (x == 1) {
				dp[pos][x] = max(go(pos + 1, x, h - t[pos].first), t[pos].second);
			} else {
				dp[pos][x] = max(go(pos + 1, x, h - t[pos].first), go(pos + 1, x - 1, h - t[pos].first) + t[pos].second);
			}
		}
	}

	return dp[pos][x];
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);

	scanf("%d", &h);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i].first, &t[i].second);
	}

	sort(t, t + n);

	reverse(t, t + n);

	cout << go(0, 1, 0) << endl;

	return 0;
}