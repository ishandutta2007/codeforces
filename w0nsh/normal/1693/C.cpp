#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


constexpr int INF = 1000000666;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<VI> g(n), inv(n);
	VI dist(n, INF);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(a == n-1) continue;
		g[a].push_back(b);
		inv[b].push_back(a);
	}

	dist[n-1] = 0;
	std::priority_queue<PII> que;
	VI deg(n);
	FOR(i, n) deg[i] = SZ(g[i]);
	std::vector<bool> vis(n);
	vis[n-1] = true;
	TRAV(ch, inv[n-1]){
		deg[ch]--;
		dist[ch] = deg[ch] + 1;
		que.push(MP(-dist[ch], ch));
	}

	while(SZ(que)){
		auto[_, v] = que.top();
		que.pop();
		if(vis[v]) continue;
		vis[v] = true;

		TRAV(ch, inv[v]){
			deg[ch]--;
			int cand = deg[ch] + 1 + dist[v];
			if(cand < dist[ch]){
				dist[ch] = cand;
				que.push(MP(-dist[ch], ch));
			}
		}
	}

	std::cout << dist[0] << "\n";

	return 0;
}