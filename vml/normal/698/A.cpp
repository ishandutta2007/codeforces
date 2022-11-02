#pragma comment(linker, "/STACK:3200000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = 110;

int dp[maxn][3];
int v[maxn];

int n;

int go(int pos, int x) {
	if (dp[pos][x] != -1) {
		return dp[pos][x];
	}

	if (pos == n) {
		dp[pos][x] = 0;
	} else {
		int ans = 100000;
		for (int i = 0; i <= 2; i++) {
			if (i == 0) {
				ans = min(ans, go(pos + 1, 0) + 1);
			} else if (i == 1 && (v[pos] == 1 || v[pos] == 3) && x != 1) {
				ans = min(ans, go(pos + 1, 1));
			} else if (i == 2 && (v[pos] == 2 || v[pos] == 3) && x != 2) {
				ans = min(ans, go(pos + 1, 2));
			}
		}

		dp[pos][x] = ans;
	}

	return dp[pos][x];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	memset(dp, -1, sizeof dp);

	cout << go(0, 0) << endl;

	return 0;
}