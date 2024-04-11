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
const int maxn = (int)1e6 + 10;
int v[maxn];
bool used[maxn];

int dfs(int x) {
	if (used[x]) {
		return 0;
	}

	used[x] = true;

	return 1 + dfs(v[x]);
}

int ans[maxn];
bool us[maxn];

int go(int x, int y) {
	if (used[x]) {
		return 0;
	}

	if (us[y]) {
		return -10000;
	}

	used[x] = true;
	us[y] = true;

	ans[x] = y;

	return 1 + go(y, v[x]);
}

int getr(int x, int cnt) {
	if (cnt == 0) {
		return x;
	}

	return getr(v[x], cnt - 1);
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	memset(used, 0, sizeof used);

	int cnt = 0;

	set <pair <int, int> > s;

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt++;
			s.insert(make_pair(dfs(i), i));
		}
	}

	memset(used, 0, sizeof used);

	for (auto it = s.begin(); it != s.end(); it++) {
		if (it->first % 2 == 1) {
			int x = getr(it->second, (it->first + 1) / 2);

			go(it->second, x);
		} else {
			pair <int, int> a = *it;
			it++;

			if (it == s.end() || it->first != a.first) {
				cout << -1 << endl;
				return 0;
			}

			go(a.second, it->second);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}