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

const int maxn = 2010;

int dp[maxn][maxn][2];
pair <pair <int, int>, int> lnk[maxn][maxn][2];
int v[maxn];
int l[maxn];
int r[maxn];
set <int> s;
int n;

int dst(int x, int y) {
	if (x <= y) {
		return y - x;
	}

	return n - x + y;
}

int ddst(int x, int y) {
	return min(dst(x, y), dst(y, x));
}

int go(int pos1, int pos2, int tp) {
	if (dp[pos1][pos2][tp] == -1) {
		if (pos1 == pos2) {
			auto it = s.upper_bound(v[pos1]);

			if (it == s.end()) {
				dp[pos1][pos2][tp] = 0;
			} else {
				dp[pos1][pos2][tp] = (int)1e9;
				forn(i, n) {
					if (v[i] == *it) {
						if (dp[pos1][pos2][tp] > go(i, l[i], 0) + ddst(pos1, i)) {
							dp[pos1][pos2][tp] = min(dp[pos1][pos2][tp], go(i, l[i], 0) + ddst(pos1, i));
							lnk[pos1][pos2][tp] = make_pair(make_pair(i, l[i]), 0);
						}
					}
				}
			}
		} else if (tp == 0) {
			dp[pos1][pos2][tp] = go(r[pos1], pos2, tp) + ddst(pos1, r[pos1]);
			lnk[pos1][pos2][tp] = mp(mp(r[pos1], pos2), tp);
			if (dp[pos1][pos2][tp] > go(pos2, r[pos1], 1) + ddst(pos1, pos2)) {
				dp[pos1][pos2][tp] = min(dp[pos1][pos2][tp], go(pos2, r[pos1], 1) + ddst(pos1, pos2));
				lnk[pos1][pos2][tp] = make_pair(make_pair(pos2, r[pos1]), 1);
			}
		} else {
			dp[pos1][pos2][tp] = go(l[pos1], pos2, tp) + ddst(pos1, l[pos1]);
			lnk[pos1][pos2][tp] = mp(mp(l[pos1], pos2), tp);
			if (dp[pos1][pos2][tp] > go(pos2, l[pos1], 0) + ddst(pos1, pos2)) {
				dp[pos1][pos2][tp] = min(dp[pos1][pos2][tp], go(pos2, l[pos1], 0) + ddst(pos1, pos2));
				lnk[pos1][pos2][tp] = mp(mp(pos2, l[pos1]), 0);
			}
		}
	}

	return dp[pos1][pos2][tp];
}

void make_ans(int pos1, int pos2, int tp) {
	if (dp[pos1][pos2][tp] == -1) {
		throw 1;
	}

	if (dp[pos1][pos2][tp] == 0) {
		return;
	}

	int apos1 = lnk[pos1][pos2][tp].first.first;
	int apos2 = lnk[pos1][pos2][tp].first.second;
	int atp = lnk[pos1][pos2][tp].second;

	if (dst(pos1, apos1) <= dst(apos1, pos1)) {
		cout << "+" << dst(pos1, apos1) << endl;
	} else {
		cout << "-" << dst(apos1, pos1) << endl;
	}

	make_ans(apos1, apos2, atp);
}

int main() {
	int st;
	cin >> n >> st;
	st--;

	forn(i, n) {
		cin >> v[i];
		s.insert(v[i]);
	}

	forn(i, n) {
		int left = i - 1;

		if (left < 0) {
			left = n - 1;
		}

		while (v[left] != v[i]) {
			left--;

			if (left < 0) {
				left = n - 1;
			}
		}

		l[i] = left;

		int right = i + 1;

		if (right == n) {
			right = 0;
		}

		while (v[right] != v[i]) {
			right++;

			if (right == n) {
				right = 0;
			}
		}

		r[i] = right;
	}

	memset(dp, -1, sizeof dp);

	int bpos = -1;

	forn(i, n) {
		if (v[i] == *s.begin()) {
			if (bpos == -1 || go(bpos, l[bpos], 0) + ddst(st, bpos) > go(i, l[i], 0) + ddst(st, i)) {
				bpos = i;
			}
		}
	}

	cout << go(bpos, l[bpos], 0) + ddst(st, bpos) << endl;

	if (dst(st, bpos) <= dst(bpos, st)) {
		cout << "+" << dst(st, bpos) << endl;
	} else {
		cout << "-" << dst(bpos, st) << endl;
	}

	make_ans(bpos, l[bpos], 0);

	return 0;
}