#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005, M = N << 1, INF = 1000000000;
int n, m, d, v[M], head[N], next[M], maxChild[N][2], fa[N], ma[N], top;
bool affect[N];
vector<int> order;
void dfs(const int i) {
	order.push_back(i);
	maxChild[i][0] = maxChild[i][1] = -INF;
	ma[i] = -INF;
	for (int j = head[i]; j != -1; j = next[j]) {
		int u = v[j];
		if (u != fa[i]) {
			fa[u] = i;
			dfs(u);
			int disu = max(maxChild[u][0] + 1, affect[u] ? 0 : -INF);
			if (disu > maxChild[i][0]) {
				maxChild[i][1] = maxChild[i][0];
				maxChild[i][0] = disu;
				ma[i] = u;
			} else if (disu > maxChild[i][1]) {
				maxChild[i][1] = disu;
			}
		}
	}
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; ++i) {
		int t1;
		scanf("%d", &t1);
		--t1;
		affect[t1] = true;
	}
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		v[top] = t2; next[top] = head[t1]; head[t1] = top; ++top;
		v[top] = t1; next[top] = head[t2]; head[t2] = top; ++top;
	}
	dfs(0);
	int ans = 0;
	for (int _ = 0; _ < n; ++_) {
		int i = order[_];
		int fardis = maxChild[i][0] + 1;
		if (i != 0) {
			int fadis = maxChild[fa[i]][ma[fa[i]] == i ? 1 : 0] + 1;
			if (affect[fa[i]]) {
				fadis = max(fadis, 0);
			}
			if (fadis > maxChild[i][0]) {
				maxChild[i][1] = maxChild[i][0];
				maxChild[i][0] = fadis;
				ma[i] = fa[i];
			} else if (fadis > maxChild[i][1]) {
				maxChild[i][1] = fadis;
			}
			fardis = max(fardis, fadis + 1);
		}
		if (affect[i]) {
			fardis = max(fardis, 0);
		}
		if (fardis <= d) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}