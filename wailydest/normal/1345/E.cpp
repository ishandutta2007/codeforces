#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int N = 200000;

vector<int> m[N], l[N];

int state[N];

bool check(int v) 
{
	if (state[v] == 1) return false;
	else if (state[v]) return true;
	state[v] = 1;
	for (int i = 0; i < m[v].size(); ++i) if (!check(m[v][i])) return false;
	state[v] = 2;
	return true;
}

set<pair<int, int> > s;

int type[N];

bool vis[N][2];

void dfs(vector<int> *g, int v, int tp) 
{
	vis[v][tp] = true;
	for (int i = 0; i < g[v].size(); ++i) if (!vis[g[v][i]][tp]) {
		dfs(g, g[v][i], tp);
		type[g[v][i]] = 2;
	}
}

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	int a, b;
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &a, &b);
		if (!s.count(make_pair(a, b))) {
			m[a - 1].push_back(b - 1);
			l[b - 1].push_back(a - 1);
			s.insert(make_pair(a, b));
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!state[i] && !check(i)) {
			printf("-1\n");
			return 0;
		}
	}
	int amount = 0;
	for (int i = 0; i < n; ++i) {
		if (!type[i]) {
			++amount;
			type[i] = 1;
		}
		if (!vis[i][0]) dfs(m, i, 0);
		if (!vis[i][1]) dfs(l, i, 1);
	}
	printf("%d\n", amount);
	for (int i = 0; i < n; ++i) {
		if (type[i] == 1) printf("A");
		else printf("E");
	}
	printf("\n");
	return 0;
}