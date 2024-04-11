#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005, M = N << 1;
int n, head[N], to[M], next[M], fa[N], fdis[N], tans[N];

int main() {
	int top = 0;
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		to[top] = t2, next[top] = head[t1], head[t1] = top, ++top;
		to[top] = t1, next[top] = head[t2], head[t2] = top, ++top;
	}
	int ans = n - 1;
	for (int i = 0; i < n; ++i) {
		queue<int> q;
		vector<int> v;
		q.push(i);
		memset(fa, -1, sizeof(fa));
		int all_cost = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (int j = head[u]; ~j; j = next[j]) {
				int v = to[j], d = j & 1;
				if (v == fa[u]) {
					continue;
				}
				fa[v] = u;
				fdis[v] = d ? 1 : -1;
				all_cost += d;
				q.push(v);
			}
			v.push_back(u);
		}
		tans[i] = all_cost;
		ans = min(ans, all_cost);
		for (int j = 1; j < n; ++j) {
			int r = v[j], f = fa[v[j]];
			tans[r] = min(all_cost, tans[f] - fdis[r]);
			ans = min(ans, tans[r]);
		}
	}
	printf("%d\n", ans);
	return 0;
}