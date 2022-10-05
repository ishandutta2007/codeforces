#include <bits/stdc++.h>
const int N = 5e5 + 10;
#define ll long long
using namespace std;
int n, m, Edge[N][2], w[N], id[N];
int q, fa[N];
bool out[N];
map<int, vector<int> > M1, M2[N];
bool cmp(int i, int j) {
	return w[i] < w[j];
}
int top, val[N];
int *stk[N];
int modf(int *x, int y) {
	stk[++ top] = x, val[top] = (*x);
	(*x) = y;
	return y;
}
void reload() {
	while (top) {
		(*stk[top]) = val[top];
		top --;
	}
}
int find(int x) {
	if (x == fa[x]) return x;
	return modf(fa + x, find(fa[x]));
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d%d%d", Edge[i] + 0, Edge[i] + 1, w + i), id[i] = i;
	scanf("%d", &q);
	for (int i = 1, k; i <= q; i ++) {
		scanf("%d", &k);
		for (int j = 1, x; j <= k; j ++) {
			scanf("%d", &x);
			if (M1[w[x]].size() == 0 || M1[w[x]][M1[w[x]].size() - 1] != i) M1[w[x]].push_back(i);
			M2[i][w[x]].push_back(x);
		}
	}
	sort(id + 1, id + m + 1, cmp);
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++) {
		int L = i, R = i;
		while (w[id[R + 1]] == w[id[L]] && R + 1 <= m) R ++;
		for (int j = 0; j < M1[w[id[i]]].size(); j ++) {
			int qid = M1[w[id[i]]][j];
			if (out[qid]) continue;

			for (int k = 0; k < M2[qid][w[id[i]]].size(); k ++) {
				int E = M2[qid][w[id[i]]][k];
				int u = Edge[E][0], v = Edge[E][1];
				if (find(u) != find(v)) {
					modf(&fa[find(u)], find(v));
				} else {
					out[qid] = 1;
					break;
				}
			}

			reload();
		}
		for (int j = L; j <= R; j ++) {
			int E = id[j];
			int u = Edge[E][0], v = Edge[E][1];
			if (find(u) != find(v)) modf(&fa[find(u)], find(v));
		}
		top = 0;
		i = R;
	}
	for (int i = 1; i <= q; i ++)
		puts(out[i] ? "NO" : "YES");

	return 0;
}