#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,lzcnt,popcnt")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

const int N = 100005;
const int K = 500;
const int M = 5;
int n, m, val[N * M], occ[N * M], ind[K];
unsigned long long cur[N], all[K][N];
std::vector<int> pos[N * M];

struct item {
	int w, x[M];
} a[N];

bool operator<(item &a, item &b) {
	return a.w < b.w;
}

int main() {
	scanf("%d%d", &n, &m);
	int amt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i].x[j]);
			val[amt++] = a[i].x[j];
		}
		scanf("%d", &a[i].w);
	}
	std::sort(a, a + n);
	std::sort(val, val + amt);
	amt = std::unique(val, val + amt) - val;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		a[i].x[j] = std::lower_bound(val, val + amt, a[i].x[j]) - val;
		++occ[a[i].x[j]];
	}
	for (int i = 0, j = 0; i < amt; ++i) if (occ[i] >= K) ind[i] = j++;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (occ[a[i].x[j]] >= K) all[ind[a[i].x[j]]][i >> 6] |= (unsigned long long)1 << (i & 63);
		else pos[a[i].x[j]].push_back(i);
	}
	int ans = ~(1 << 31);
	for (int i = 0; i < n; ++i) {
		int until = i / 64 + 1;
		for (int j = 0; j < m; ++j) {
			int val = a[i].x[j];
			if (occ[val] >= K) {
				int id = ind[val];
				for (int k = 0; k < until; ++k) cur[k] |= all[id][k];
			} else {
				for (int k = 0; k < (int)pos[val].size(); ++k) cur[pos[val][k] >> 6] |= (unsigned long long)1 << (pos[val][k] & 63);
			}
		}
		if (i) {
			int j;
			for (j = 0; j < until && cur[j] == ULLONG_MAX; ++j);
			if (j != until) {
				int pos;
				for (pos = 0; cur[j] >> pos & 1; ++pos);
				pos += j * 64;
				if (pos < i) ans = std::min(ans, a[i].w + a[pos].w);
			}
		}
		for (int j = 0; j <= until; ++j) cur[j] = 0;
	}
	if (ans == ~(1 << 31)) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}