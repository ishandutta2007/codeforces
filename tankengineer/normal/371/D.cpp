#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

const int N = 2 * 100000 + 1;
int a[N], b[N], fa[N];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	if (u == v) {
		return;
	}
	fa[u] = v;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		fa[i] = i;
	}
	fa[n] = n;
	int m;
	scanf("%d", &m);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int id, x;
			scanf("%d%d", &id, &x);
			--id;
			while (x) {
				int t = find(id), tmp = min(x, a[t] - b[t]);
				if (t >= n) {
					break;
				}
				x -= tmp;
				b[t] += tmp;
				if (b[t] == a[t]) {
					int t2 = find(t + 1);
					merge(t, t2);
				}
			}
		} else {
			int id;
			scanf("%d", &id);
			--id;
			printf("%d\n", b[id]);
		}
	}
	return 0;
}