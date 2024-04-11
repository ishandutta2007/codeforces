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
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

struct point {
	int next[26];
	int sum;
	int lnk;
	int p;
	char pc;
};

const int maxn = 210;

point mas[maxn];
int pos = 0;

int my_new(int p, char pc) {
	memset(mas[pos].next, -1, sizeof mas[pos].next);
	mas[pos].p = p;
	mas[pos].pc = pc;
	mas[pos].sum = 0;
	mas[pos].lnk = -1;

	return pos++;
}

string s;
int a[maxn];

void add(int p, int it, int x) {
	if (p == (int)s.size()) {
		mas[it].sum += x;
	} else {
		int g = s[p] - 'a';

		if (mas[it].next[g] == -1) {
			mas[it].next[g] = my_new(it, g);
		}

		add(p + 1, mas[it].next[g], x);
	}
}

int go(int v, int c);

int get_lnk(int v) {
	if (mas[v].lnk != -1) {
		return mas[v].lnk;
	}

	if (v == 0 || mas[v].p == 0) {
		mas[v].lnk = 0;
	} else {
		mas[v].lnk = go(get_lnk(mas[v].p), mas[v].pc);
	}

	return mas[v].lnk;
}

int go(int v, int c) {
	if (mas[v].next[c] != -1) {
		return mas[v].next[c];
	}

	if (v == 0) {
		mas[v].next[c] = 0;
	} else {
		mas[v].next[c] = go(get_lnk(v), c);
	}

	return mas[v].next[c];
}

bool used[maxn];

int make(int v) {
	if (used[v]) {
		return mas[v].sum;
	}

	used[v] = true;

	mas[v].sum += make(get_lnk(v));

	return mas[v].sum;
}

ll x[maxn][maxn];
ll now[maxn][maxn];
ll buf[maxn][maxn];

void get_ans(ll cnt) {
	if (cnt == 1) {
		for (int i = 0; i < pos; i++) {
			for (int j = 0; j < pos; j++) {
				now[i][j] = x[i][j];
			}
		}
		return;
	}

	if (cnt % 2 == 0) {
		get_ans(cnt / 2);

		memset(buf, -1, sizeof buf);

		for (int i = 0; i < pos; i++) {
			for (int j = 0; j < pos; j++) {
				for (int k = 0; k < pos; k++) {
					if (now[i][k] != -1 && now[k][j] != -1) {
						buf[i][j] = max(buf[i][j], now[i][k] + now[k][j]);
					}
				}
			}
		}
	} else {
		get_ans(cnt - 1);

		memset(buf, -1, sizeof buf);

		for (int i = 0; i < pos; i++) {
			for (int j = 0; j < pos; j++) {
				for (int k = 0; k < pos; k++) {
					if (now[i][k] != -1 && x[k][j] != -1) {
						buf[i][j] = max(buf[i][j], now[i][k] + x[k][j]);
					}
				}
			}
		}
	}

	for (int i = 0; i < pos; i++) {
		for (int j = 0; j < pos; j++) {
			now[i][j] = buf[i][j];
		}
	}
}

int main() {
	int n;

	cin >> n;

	ll l;

	cin >> l;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int t = my_new(-1, 0);

	for (int i = 0; i < n; i++) {
		cin >> s;

		add(0, t, a[i]);
	}

	for (int i = 0; i < pos; i++) {
		make(i);
	}

	memset(x, -1, sizeof x);

	for (int i = 0; i < pos; i++) {
		for (int j = 0; j < 26; j++) {
			int r = go(i, j);

			if (x[i][r] == -1) {
				x[i][r] = mas[r].sum;
			} else {
				x[i][r] += mas[r].sum;
			}
		}
	}

	get_ans(l);

	ll res = 0;

	for (int i = 0; i < pos; i++) {
		res = max(res, now[0][i]);
	}

	cout << res << endl;

	return 0;
}