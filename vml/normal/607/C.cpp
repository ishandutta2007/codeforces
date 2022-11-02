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

const int maxn = (int)2e6 + 10;
char s[2][maxn];
int n;

ll hsh[2][maxn];
ll p = (int)1e9 + 7;
ll t[maxn];

int un(char c) {
	if (c == 'S') {
		return 'N';
	}

	if (c == 'N') {
		return 'S';
	}

	if (c == 'E') {
		return 'W';
	}

	return 'E';
}

int go(int x, int pos, char c) {
	if (pos != n && s[x][pos] == c) {
		return pos + 1;
	}

	if (pos != 0 && s[x][pos - 1] == un(c)) {
		return pos - 1;
	}

	return pos;
}

ll go_hash(int x, int l, int r) {
	if (x == 1) {
		if (l == 0) {
			return hsh[x][r];
		} else {
			ll f = hsh[x][r] - hsh[x][l - 1] * t[r - l + 1];
			f %= p;

			if (f < 0) {
				return f + p;
			}

			return f;
		}
	} else {
		if (l == n - 1) {
			return hsh[x][r];
		} else {
			ll f = hsh[x][r] - hsh[x][l + 1] * t[l - r + 1];
			f %= p;

			if (f < 0) {
				return f + p;
			}

			return f;
		}
	}
}

bool went() {
	int pos1 = 0;
	int pos2 = 0;

	while (pos1 != n) {
		pos2 = go(1, pos2, s[0][pos1]);
		pos1 = go(0, pos1, s[0][pos1]);
	}

	while (pos2 != n) {
		int l = 0;
		int r = n - pos2;

		while (l != r) {
			int m = (l + r + 1) / 2;

			if (go_hash(1, pos2, pos2 + m - 1) == go_hash(0, pos1 - 1, pos1 - m)) {
				l = m;
			} else {
				r = m - 1;
			}
		}

		pos2 += l;
		pos1 -= l;
		
		if (pos2 == n) {
			return false;
		}

		pos2++;

		while (pos1 != n) {
			l = 0;
			r = n - pos1;

			while (l != r) {
				int m = (l + r + 1) / 2;

				if (go_hash(1, pos2 - m, pos2 - 1) == go_hash(0, pos1 + m - 1, pos1)) {
					l = m;
				} else {
					r = m - 1;
				}
			}

			pos1 += l;
			pos2 -= l;
			
			if (pos1 != n) {
				pos1++;
			}
		}
	}

	return true;
}

int main() {
	t[0] = 1;

	for (int i = 1; i < maxn; i++) {
		t[i] = t[i - 1] * 1234567;
		t[i] %= p;
	}

	cin >> n;
	n--;

	scanf("%s", s[0]);
	scanf("%s", s[1]);

	ll now = 0;

	for (int i = n - 1; i >= 0; i--) {
		now *= t[1];
		now += un(s[0][i]);
		now %= p;

		hsh[0][i] = now;
	}

	now = 0;

	for (int i = 0; i < n; i++) {
		now *= t[1];
		now += s[1][i];
		now %= p;

		hsh[1][i] = now;
	}

	if (went()) {
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}