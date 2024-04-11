#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 210;

struct vt {
	int x;
	char tx;
	int y;
	char ty;

	vt(): x(0), tx(0), y(0), ty(0) {

	}

	vt(int x, char tx, int y, char ty): x(x), tx(tx), y(y), ty(ty) {

	}
};

vector <vt> v[maxn];

string s;

int f[maxn];

int now[maxn];
int us[maxn];
int nnow[maxn];

int n;
int x = -1;

bool dfs(int u, int t) {
	if (us[u] != -1 && s[us[u]] != s[t]) {
		return false;
	}

	if (us[u] != -1) {
		return true;
	}

	us[u] = t;

	for (int i = 0; i < (int)v[u].size(); i++) {
		if (v[u][i].x == u) {
			if (v[u][i].tx == s[t]) {
				int pos = x;
				if (v[u][i].ty == s[0]) {
					pos = 0;
				}

				if (pos == -1) {
					return false;
				}
				
				if (!dfs(v[u][i].y, pos)) {
					return false;
				}
			}
		} else {
			if (v[u][i].ty != s[t]) {
				int pos = 0;

				if (v[u][i].tx == s[0]) {
					pos = x;
				}

				if (pos == -1) {
					return false;
				}

				if (!dfs(v[u][i].x, pos)) {
					return false;
				}
			}
		}
	}

	return true;
}

int kk;

bool dfs1(int u, int t) {
	if (nnow[u] != -1 && s[nnow[u]] != s[t]) {
		return false;
	}

	if (nnow[u] != -1) {
		return true;
	}

	nnow[u] = t;

	for (int i = 0; i < (int)v[u].size(); i++) {
		if (v[u][i].x == u) {
			if (v[u][i].tx == s[t]) {
				int pos = x;
				if (v[u][i].ty == s[0]) {
					pos = 0;
				}

				if (pos == -1) {
					return false;
				}
				
				if (!dfs1(v[u][i].y, pos)) {
					return false;
				}
			}
		} else {
			if (v[u][i].ty != s[t]) {
				int pos = 0;

				if (v[u][i].tx == s[0]) {
					pos = x;
				}

				if (pos == -1) {
					return false;
				}

				if (!dfs1(v[u][i].x, pos)) {
					return false;
				}
			}
		}
	}

	return true;
}

bool check(int k) {
	kk = k;
	for (int i = k; i < n; i++) {
		now[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		us[i] = -1;
		nnow[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (now[i] != -1) {
			if (nnow[i] == -1) {
				if (!dfs(i, now[i])) {
					return false;
				}

				dfs1(i, now[i]);
			} else if (s[nnow[i]] != s[now[i]]) {
				return false;
			} else {
				nnow[i] = now[i];
				us[i] = now[i];
			}
		} else {
			if (dfs(i, 0)) {
				dfs1(i, 0);
			} else {
				for (int j = 0; j < n; j++) {
					us[j] = nnow[j];
				}

				if (x != -1) {
					if (dfs(i, x)) {
						dfs1(i, x);
					} else {
						return false;
					}
				} else {
					return false;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		now[i] = nnow[i]; 
	}

	return true;
}

void write() {
	for (int i = 0; i < n; i++) {
		cout << (char)('a' + now[i]);
	}
	cout << endl;
}

bool check1() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			if (i == v[i][j].x && s[now[i]] == v[i][j].tx) {
				if (!(s[now[v[i][j].y]] == v[i][j].ty)) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	cin >> s;

	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] != s[0]) {
			x = i;
			break;
		}
	}

	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		char tx, ty;

		scanf("%d %c %d %c", &x, &tx, &y, &ty);
		x--;
		y--;

		v[x].push_back(vt(x, tx, y, ty));
		v[y].push_back(vt(x, tx, y, ty));
	}

	string t;

	cin >> t;
	
	for (int i = 0; i < n; i++) {
		f[i] = t[i] - 'a';
		now[i] = t[i] - 'a';
	}

	if (check(n)) {
		if (!check1()) {
			throw 1;
		}
		write();
		return 0;
	}

	for (int i = n - 1; i >= 0; i--) {
		bool a = false;
		bool b = false;
		for (int pos = f[i] + 1; pos < (int)s.size(); pos++) {
			if (s[pos] != s[f[i]] && !b) {
				now[i] = pos;
				
				b = true;

				if (check(i + 1)) {
					if (!check1()) {
						throw 1;
					}
					
					write();
					return 0;
				}
			}

			if (s[pos] == s[f[i]] && !a) {
				now[i] = pos;
				a = true;

				if (check(i + 1)) {
					if (!check1()) {
						throw 1;
					}
					
					write();
					return 0;
				}
			}
		}
	}

	cout << "-1" << endl;

	return 0;
}