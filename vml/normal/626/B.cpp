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
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

vector <char> dp[210][210][210];

void go(int a, int b, int c) {
	if (dp[a][b][c].empty()) {
		if (a == 0 && b == 0) {
			dp[a][b][c].push_back('B');
			return;
		} else if (a == 0 && c == 0) {
			dp[a][b][c].push_back('G');
			return;
		} else if (b == 0 && c == 0) {
			dp[a][b][c].push_back('R');
			return;
		}

		if (a != 0 && b != 0) {
			int na = a - 1;
			int nb = b - 1;
			int nc = c + 1;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		if (c != 0 && b != 0) {
			int na = a + 1;
			int nb = b - 1;
			int nc = c - 1;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		if (a != 0 && c != 0) {
			int na = a - 1;
			int nb = b + 1;
			int nc = c - 1;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		if (a >= 2) {
			int na = a - 1;
			int nb = b;
			int nc = c;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		if (b >= 2) {
			int na = a;
			int nb = b - 1;
			int nc = c;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		if (c >= 2) {
			int na = a;
			int nb = b;
			int nc = c - 1;
			go(na, nb, nc);

			for (int i = 0; i < (int)dp[na][nb][nc].size(); i++) {
				dp[a][b][c].push_back(dp[na][nb][nc][i]);
			}
		}

		sort(dp[a][b][c].begin(), dp[a][b][c].end());

		dp[a][b][c].resize(unique(dp[a][b][c].begin(), dp[a][b][c].end()) - dp[a][b][c].begin());
	}
}

int main() {
	int n;

	cin >> n;

	string s;

	cin >> s;

	int a = 0, b = 0, c = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'R') {
			a++;
		} else if (s[i] == 'G') {
			b++;
		} else {
			c++;
		}
	}

	go(a, b, c);

	for (int i = 0; i < (int)dp[a][b][c].size(); i++) {
		cout << dp[a][b][c][i];
	}

	return 0;
}