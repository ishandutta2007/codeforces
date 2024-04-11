#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair

typedef pair<int, int> pii;

vector<vector<pii> > graph;
const int N = 110;
int ans[N];

void dfs(int v, int p) {
	for (auto q : graph[v]) {
		int u = q.first;
		if (u == p)
			continue;
		dfs(u, v);
		ans[v] = max(ans[v], ans[u] + q.second);
	}
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	
	int n;
	cin >> n;
	graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}
	dfs(0, -1);
	cout << ans[0] << endl;
	return 0;
}