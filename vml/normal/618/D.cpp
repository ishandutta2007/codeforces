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
#include <memory.h>

#define ll long long
#define ld double
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

const int maxn = (int)2e5 + 10;

vector <int> ed[maxn];
int dp[maxn][2];

int go(int v, int p, int c) {
	if (dp[v][c] == -1) {
		multiset <int> s;
		int ans = 0;

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (u != p) {
				s.insert(-go(u, v, 1) + go(u, v, 0));
				ans += go(u, v, 1);
			}
		}

		dp[v][c] = ans + 1;

		if (!s.empty()) {
			dp[v][c] = min(dp[v][c], ans + *s.begin());
		}

		if ((int)s.size() > 1 && c == 1) {
			ans += *s.begin();

			s.erase(s.begin());

			ans += *s.begin();

			dp[v][c] = min(dp[v][c], ans - 1);
		}
	}

	return dp[v][c];
}

int main() {
	memset(dp, -1, sizeof dp);

	int n;

	cin >> n;

	int x, y;

	cin >> x >> y;

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	if (n == 2) {
		cout << x << endl;
		return 0;
	}

	if (x >= y) {
		for (int i = 1; i <= n; i++) {
			if ((int)ed[i].size() == n - 1) {
				cout << (ll)y * (n - 2) + x << endl;
				return 0;
			}
		}

		cout << (ll)y * (n - 1);

		return 0;
	}

	cout << (ll)y * (go(1, -1, 1) - 1) + (ll)x * (n - go(1, -1, 1)) << endl;

	return 0;
}