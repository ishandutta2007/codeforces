#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, m, fa[N];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u > v) {
		swap(u, v);
	}
	fa[u] = v;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		merge(u, v);
	}
	int ans = 0, lastr = -1;
	for (int i = 0; i < n; ++i) {
		int l = i, r = find(i);
		if (l > lastr) {
			lastr = r;
		} else {
			if (r != lastr) {
				++ans;
				merge(r, lastr);
				lastr = find(i);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}