#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

const int maxn = 3 * (100000 + 10);

int v[maxn];

int main() {
#ifdef ONLINE_JUDGE
    //freopen("towers.in", "r", stdin);
    //freopen("towers.out", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	int m = 1000000;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		m = min(v[i], m);
		mn = max(v[i], mn);
	}
	sort(v, v + n);
	int ans = 1;
	for (int i = m; i >= 2; i--) {
		int pos = 0;
		bool yes = true;
		for (int j = 1; i * j <= mn; j++) {
			if (pos == n) {
				break;
			}
			int left = pos;
			int right = n - 1;
			while (left != right) {
				pos = (left + right + 1) / 2;
				if (v[pos] - i * j < i) {
					left = pos;
				} else {
					right = pos - 1;
				}
			}
			pos = left;
			if (v[pos] - i * j < i) {
				if (v[pos] - i * j > k) {
					yes = false;
					break;
				}
				pos++;
			}
		}
		if (yes) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}