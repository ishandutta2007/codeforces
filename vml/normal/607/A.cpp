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

const int maxn = (int)1e5 + 10;
pii v[maxn];
int lnk[maxn];
int dp[maxn];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v, v + n);

	lnk[0] = -1;

	for (int i = 1; i < n; i++) {
		int l = 0;
		int r = i;

		while (l != r) {
			int m = (l + r) / 2;

			if (v[m].first < v[i].first - v[i].second) {
				l = m + 1;
			} else {
				r = m;
			}
		}

		lnk[i] = l - 1;
	}

	dp[0] = 1;
	int maxx = n;

	for (int i = 0; i < n; i++) {
		if (lnk[i] != -1) {
			dp[i] = 1 + dp[lnk[i]];
		} else {
			dp[i] = 1;
		}

		maxx = min(maxx, n - dp[i]);
	}

	cout << maxx << endl;

	return 0;
}