#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct edge{
	long long u, w, num;
	edge() {}
	edge(int u, int w, int num) {
		this->u = u;
		this->w = w;
		this->num = num;
	}
};

const int MAX_N = 3e5 + 7;
vector <edge> g[MAX_N];
vector <pair <int, int>> g2[MAX_N];
vector <int> ans;
long long dist[MAX_N], edge_num[MAX_N], prevv[MAX_N]; 

set <pair <long long, long long>> d;
int need;

void dfs(int v, int pr = -1) {
	for (pair <int, int> u : g2[v]) {
		if (u.first == pr) continue;
		if (need == 0) return;
		need--;
		ans.push_back(u.second);
		dfs(u.first, v);
	}
}


int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		g[v].push_back({u, w, i});
		g[u].push_back({v, w, i});
	}
	for (int i = 2; i <= n; i++) dist[i] = -1;
	dist[0] = 0;
	d.insert({0, 1});
	while (!d.empty()) {
		pair <long long, long long> el = (*d.begin());
		d.erase(*d.begin());
		long long dd = el.first, v = el.second;
		//cout << v << endl;
		for (edge elem : g[v]) {
			long long u = elem.u, w = elem.w;
			if (dist[u] == -1) {
				d.insert({dist[v] + w, u});
				dist[u] = dist[v] + w;
				prevv[u] = v;
				edge_num[u] = elem.num;
			} else if (dist[v] + w < dist[u]) {
				d.erase({dist[u], u});
				d.insert({dist[v] + w, u});
				dist[u] = dist[v] + w;
				prevv[u] = v;
				edge_num[u] = elem.num;
			}
		}
	}
	//for (int i = 2; i <= n; i++) cout << dist[i] << ' ' << i << ' ' << edge_num[i] + 1 << endl;
	if (k >= n - 1) need = n - 1;
	else need = k;
	for (int i = 2; i <= n; i++) g2[prevv[i]].push_back({i, edge_num[i]});
	dfs(1);
	cout << ans.size() << endl;
	for (int elem : ans) cout << elem + 1 << ' ';
	cout << endl;
	return 0;
}