#pragma comment(linker, "/STACK:3200000")
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

const int maxn = 20;

int cnt[(1 << maxn)];
ld v[maxn];
ld ans[maxn];
ld t[(1 << maxn)];
bool used[(1 << maxn)];

int getcnt(int x) {
	int ans = 0;

	while (x != 0) {
		ans += x & 1;
		x >>= 1;
	}

	return ans;
}

int main() {
	for (int i = 0; i < (1 << maxn); i++) {
		cnt[i] = getcnt(i);
	}

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	queue <int> q;
	t[0] = 1.0;

	q.push(0);

	while (!q.empty()) {
		int m = q.front();
		ld x = t[m];
		q.pop();

		bool st = false;

		for (int i = 0; i < n; i++) {
			if (((m >> i) & 1) == 0 && v[i] != 0) {
				st = true;
				break;
			}
		}

		if (cnt[m] == k || !st) {
			for (int i = 0; i < n; i++) {
				if ((m & 1) == 1) {
					ans[i] += x;
				}

				m >>= 1;
			}
			continue;
		}

		ld y = 0.0;

		for (int i = 0; i < n; i++) {
			if (((m >> i) & 1) == 1) {
				y += v[i];
			}
		}

		for (int i = 0; i < n; i++) {
			if (((m >> i) & 1) == 0 && v[i] != 0) {
				int nm = m | (1 << i);

				t[nm] += x * v[i] / (1 - y);
				if (!used[nm]) {
					used[nm] = true;
					q.push(nm);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%.10lf ", ans[i]);
	}

	return 0;
}