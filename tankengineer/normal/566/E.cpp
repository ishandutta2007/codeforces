#include<cassert>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n;

bitset<1000> s[N];

vector<pair<int, int> > buckets[N];

int fa[N << 1];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	fa[find(u)] = find(v);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int t;
			scanf("%d", &t);
			s[--t].set(i);
		}
	}
	for (int i = 0; i < n << 1; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cnt = (s[i] & s[j]).count();
			if (cnt == 1) {
				merge(i, j);
				merge(i + n, j + n);
			} else if (cnt == 2 && n > 2) {
				merge(i, j + n);
				merge(i + n, j);
			} else {
				buckets[cnt].push_back(make_pair(i, j));
			}
		}
	}
	if (buckets[n].size() == n * (n - 1) / 2) {
		for (int i = 2; i <= n; ++i) {
			printf("%d %d\n", 1, i);
		}
	} else if (buckets[n].size() == 1) {
		int u = -1, v = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i].count() == n) {
				if (u == -1) {
					u = i;
				} else {
					v = i;
				}
			}
		}
		printf("%d %d\n", u + 1, v + 1);
		for (int i = 0; i < n; ++i) {
			if (i != u && i != v) {
				if (find(i) == find(u)) {
					printf("%d %d\n", i + 1, v + 1);
					merge(i, v + n);
					merge(i + n, v);
				} else {
					printf("%d %d\n", i + 1, u + 1);
					merge(i, u + n);
					merge(i + n, u);
				}
			}
		}
	} else {
		assert(buckets[n].size() == 0);
		for (int i = n; i > 0; --i) {
			for (int j = 0; j < (int)buckets[i].size(); ++j) {
				int u = buckets[i][j].first, v = buckets[i][j].second;
				if (find(u) == find(v)) {
					continue;
				}
				printf("%d %d\n", u + 1, v + 1);
				merge(u, v + n);
				merge(v, u + n);
			}
		}
	}
	return 0;
}