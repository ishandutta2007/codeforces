#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;

int n;

int in[N], p[N], a[N];

int jump[N][30], dest[N];

int ans[N];

int fa[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[x] = y;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		in[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		--p[i];
		++in[p[i]];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (in[i] == 0) {
			++cnt;
		}
	}
	int maxa = n - 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
		maxa = max(maxa, a[i]);
	}
	int r = (maxa - (n - 1)) / cnt;
	for (int i = 0; i < n; ++i) {
		jump[i][0] = p[i];
	}
	for (int j = 1; (r >> j) > 0; ++j) {
		for (int i = 0; i < n; ++i) {
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		dest[i] = i;
		for (int j = 0; (r >> j) > 0; ++j) {
			if ((r >> j) & 1) {
				dest[i] = jump[dest[i]][j];
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		ans[i] = -1;
		assert(a[dest[i]] < n);
		if (find(a[dest[i]]) == a[dest[i]]) {
			ans[i] = find(a[dest[i]]);
			merge(ans[i], find(ans[i] + 1));
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			ans[i] = find(a[dest[i]]);
			merge(ans[i], find(ans[i] + 1));
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}