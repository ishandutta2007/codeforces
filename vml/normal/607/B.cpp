#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <cstring>
#include <ctime>
#include <map>
#include <bitset>
#define ld double
#define ll long long
#define mp make_pair
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

const int maxn = 510;
int v[maxn];
int dp[maxn][maxn];

int go(int l, int r) {
	if (dp[l][r] == -1) {
		if (l == r) {
			dp[l][r] = 1;
		} else if (r - l == 1) {
			if (v[l] == v[r]) {
				dp[l][r] = 1;
			} else {
				dp[l][r] = 2;
			}
		} else {
			dp[l][r] = go(l + 1, r) + 1;
			for (int i = l + 1; i < r; i++) {
				if (v[l] == v[i]) {
					dp[l][r] = min(dp[l][r], go(l, i) + go(i + 1, r));
				}
			}

			if (v[l] == v[r]) {
				dp[l][r] = min(dp[l][r], go(l + 1, r - 1));
			}
		}
	}

	return dp[l][r];
}

int main() {
	int n;

	cin >> n;

	forn(i, n) {
		cin >> v[i];
	}

	memset(dp, -1, sizeof dp);

	cout << go(0, n - 1) << endl;

	return 0;
}