#include<vector>
#include<cstdio>

using namespace std;

const int N = 100005;

int n, m, k;

bool hasstorage[N];

vector<int> edge[N], len[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		--u, --v;
		edge[u].push_back(v);
		len[u].push_back(l);
		edge[v].push_back(u);
		len[v].push_back(l);
	}
	for (int i = 0; i < k; ++i) {
		int u;
		scanf("%d", &u);
		--u;
		hasstorage[u] = true;
	}
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (hasstorage[i]) {
			int u = i;
			for (int j = 0; j < (int)edge[u].size(); ++j) {
				int v = edge[u][j], tmp = len[u][j];
				if (!hasstorage[v]) {
					if (ans == -1 || ans > tmp) {
						ans = tmp;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}