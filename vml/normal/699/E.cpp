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

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = 20;

ld v[maxn];
ld f[1 << maxn];
bool used[1 << maxn];
ld ans[maxn];

int get_cnt(int mask) {
	int ans = 0;

	while (mask != 0) {
		ans += mask & 1;
		mask >>= 1;
	}

	return ans;
}

int main() {
	int n, k;

	cin >> n >> k;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lf", &v[i]);

		if (v[i] != 0) {
			cnt++;
		}
	}

	if (cnt <= k) {
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) {
				cout << 0 << ' ';
			} else {
				cout << 1 << ' ';
			}
		}
		return 0;
	}

	queue <int> q;
	q.push(0);

	f[0] = 1;
	used[0] = true;

	while (!q.empty()) {
		int m = q.front();
		ld x = f[m];
		q.pop();

		if (get_cnt(m) == k) {
			for (int i = 0; i < n; i++) {
				if ((m & 1) == 1) {
					ans[i] += x;
				}

				m >>= 1;
			}
			continue;
		}

		ld t = 0;

		for (int i = 0; i < n; i++) {
			if (((m >> i) & 1) == 1) {
				t += v[i];
			}
		}

		for (int i = 0; i < n; i++) {
			if (((m >> i) & 1) == 0) {
				int nm = m | (1 << i);
				f[nm] += v[i] * x / (1 - t);
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