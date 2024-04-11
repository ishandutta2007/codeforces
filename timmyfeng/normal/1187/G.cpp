#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MXN = 6e3;
const int MXM = 6e6;

tuple<int, int, int, int> edge[MXM];
vector<int> adj[MXN];
int pre[MXN], cnt;
bool inq[MXN];
ll dist[MXN];

void addedge(int u, int v, int f, int c) {
	adj[u].push_back(cnt);
	edge[cnt++] = make_tuple(u, v, f, c);
	adj[v].push_back(cnt);
	edge[cnt++] = make_tuple(v, u, 0, -c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, c, d;
	cin >> n >> m >> k >> c >> d;
	int s = (2 * k + 1) * n + 1;
	int t = s + 1;
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		addedge(s, a, 1, 0);
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		for (int j = 0; j < k * 2; ++j) {
			for (int l = 1; l <= k; ++l) {
				addedge(j * n + u, (j + 1) * n + v, 1, (2 * l - 1) * d);
				addedge(j * n + v, (j + 1) * n + u, 1, (2 * l - 1) * d);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k * 2; ++j) {
			addedge(j * n + i, (j + 1) * n + i, k, 0);
		}
	}
	for (int i = 0; i <= k * 2; ++i) {
		addedge(i * n + 1, t, k, i * c);
	}

	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		memset(inq, false, sizeof inq);
		memset(pre, -1, sizeof pre);
		fill(dist, dist + MXN, 1e18);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (auto e : adj[u]) {
				auto [ignore, v, c, w] = edge[e];
				if (!c) continue;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pre[v] = e;
					if (!inq[v]) {
						q.push(v);
						inq[v] = true;
					}
				}
			}
		}
		for (int j = t; j != s; j = get<0>(edge[pre[j]])) {
			--get<2>(edge[pre[j]]);
			++get<2>(edge[pre[j] ^ 1]);
		}
		ans += dist[t];
	}
	cout << ans << '\n';
}