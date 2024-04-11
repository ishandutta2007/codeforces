#include <bits/stdc++.h> 
using namespace std;

const int MX = 405;
const int MXE = 5000;
const int S = 401;
const int T = 402;
const int S1 = 403;
const int T1 = 404;
const int INF = 1e9;

vector<tuple<int, int, int, int>> edge;
int ans, flow, cnt, dist[MX], pre[MX];
vector<int> adj[MX];
bool inq[MX];

void addedge(int u, int v, int w, int c) {
	adj[u].push_back(edge.size());
	edge.emplace_back(u, v, w, c);
	adj[v].push_back(edge.size());
	edge.emplace_back(v, u, -w, 0);
}

void demand(int u, int v, int w, int d, int c) {
	cnt += d;
	addedge(S1, v, 0, d);
	addedge(u, T1, 0, d);
	addedge(u, v, w, c - d);
}

bool augment() {
	memset(inq, false, sizeof inq);
	memset(pre, 0, sizeof pre);
	fill(dist, dist + MX, INF);
	dist[S1] = 0;
	queue<int> q;
	q.push(S1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto e : adj[u]) {
			auto [u, v, w, c] = edge[e];
			if (c && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pre[v] = e;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}

	if (dist[T1] == INF)
		return false;

	int cur = T1, mn = INF;
	while (cur != S1) {
		auto [u, v, w, c] = edge[pre[cur]];
		mn = min(mn, c);
		cur = u;
	}

	flow += mn;
	ans += dist[T1] * mn;
	cur = T1;
	while (cur != S1) {
		int e = pre[cur];
		get<3>(edge[e]) -= mn;
		get<3>(edge[e ^ 1]) += mn;
		cur = get<0>(edge[e]);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, m, r, b;
	string s1, s2;
	cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		addedge(u, n1 + v, r, 1);
		addedge(n1 + v, u, b, 1);
	}
	for (int i = 1; i <= n1 + n2; ++i) {
		int col = 0;
		if (i <= n1) {
			col = (s1[i - 1] == 'R' ? 1 : (s1[i - 1] == 'B' ? 2 : 0));
		} else {
			col = (s2[i - 1 - n1] == 'B' ? 1 : (s2[i - 1 - n1] == 'R' ? 2 : 0));
		}
		if (col == 1) {
			demand(S, i, 0, 1, INF);
		} else if (col == 2) {
			demand(i, T, 0, 1, INF);
		} else {
			addedge(S, i, 0, INF);
			addedge(i, T, 0, INF);
		}
	}
	addedge(T, S, 0, INF);

	while (augment());
	if (flow < cnt) {
		cout << -1 << '\n';
		return 0;
	} else {
		cout << ans << '\n';
		for (int i = 0; i < 4 * m; i += 4) {
			if (get<3>(edge[i + 1])) {
				cout << 'R';
			} else if (get<3>(edge[i + 3])) {
				cout << 'B';
			} else {
				cout << 'U';
			}
		}
		cout << '\n';
	}
}