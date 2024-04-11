#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, x[N];
long long y[N];

const int LOG = 18;
int dep[N], fa[N][LOG];

// I64dCAUTION!!!!

bool judge(int i, int j, int k) {
	long long x1 = x[j] - x[i], x2 = x[k] - x[i],
			  y1 = y[j] - y[i], y2 = y[k] - y[i];
	return y1 * x2 < y2 * x1;
}

bool judge2(int i, int j, int k) {
	long long x1 = x[i] - x[j], x2 = x[i] - x[k],
			  y1 = y[j] - y[i], y2 = y[k] - y[i];
	return y1 * x2 < y2 * x1;
}

int lca(int u, int v) {
	if (u == v) {
		return u;
	}
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	int l = dep[u] - dep[v];
	for (int i = LOG - 1; i >= 0; --i) {
		if (l >> i & 1) {
			u = fa[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i], v = fa[v][i];
		}
	}
	return fa[u][0];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%I64d", x + i, y + i);
	}
	memset(fa, -1, sizeof(fa));
	vector<int> stack;	
	vector<int> stack2;
	stack.push_back(n - 1);
	stack2.push_back(n - 1);
	dep[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		int back = stack.front();
		while (stack.size() && y[i] >= y[stack.back()]) {
			stack.pop_back();
		}
		if (stack.size() == 0) {
			while (stack2.size() > 1 && judge2(stack2[stack2.size() - 2], stack2.back(), i)) {
				stack2.pop_back();
			}
			fa[i][0] = stack2.back();
			stack2.push_back(i);
		} else {
			while (stack.size() > 1 && judge(i, stack.back(), stack[stack.size() - 2]) ) {
				stack.pop_back();
			}
			fa[i][0] = stack.back();
		}
		stack.push_back(i);
		dep[i] = dep[fa[i][0]] + 1;
	}
	for (int i = 1; (1 << i) <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (fa[j][i - 1] == -1) {
				fa[j][i] = -1;
			} else {
				fa[j][i] = fa[fa[j][i - 1]][i - 1];
			}
		}
	}
	int q = 0;
	scanf("%d", &q);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		printf("%d%c", lca(u, v) + 1, q ? ' ' : '\n');
	}
	return 0;
}