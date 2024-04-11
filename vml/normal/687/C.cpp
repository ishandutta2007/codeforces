#pragma comment(linker, "/STACK:1000000000")
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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = 510;

int dp[2][maxn][maxn];
int v[maxn];
int n, k;
int it = 0;

void go() {
	memset(dp, 0, sizeof dp);

	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++) {
		memset(dp[it ^ 1], 0, sizeof dp[it ^ 1]);

		for (int j = 0; j <= k; j++) {
			for (int t = 0; t <= k; t++) {
				if (dp[it][j][t] == 1) {
					dp[it ^ 1][j][t] = 1;
					if (j + v[i] <= k)
						dp[it ^ 1][j + v[i]][t] = 1;
					if (t + v[i] <= k)
						dp[it ^ 1][j][t + v[i]] = 1;
				}
			}
		}

		it ^= 1;
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	vector <int> ans;

	go();

	for (int i = 0; i <= k; i++) {
		if (dp[it][i][k - i] == 1) {
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}