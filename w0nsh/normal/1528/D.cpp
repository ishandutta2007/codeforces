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

ll cost[605][605];
ll dist[605][605];
constexpr ll INF = 1000000000ll*1000000000ll;
int n, m;

void dijkstra(int start){
	dist[start][start] = 0;
	std::priority_queue<PR<ll, int>> que;
	que.push(MP(0ll, start));
	std::vector<bool> done(n);
	int rdy = 0;
	while(rdy < n){
		assert(SZ(que));
		int v = que.top().Y;
		que.pop();
		if(done[v]) continue;
		rdy++;
		done[v] = true;

		int time = dist[start][v] % n;

		FOR(i, n){
			int heh = (i - time + n) % n;
			if(dist[start][i] > dist[start][v] + cost[v][heh]){
				dist[start][i] = dist[start][v] + cost[v][heh];
				que.push(MP(-dist[start][i], i));
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n >> m;
	FOR(i, n) FOR(j, n) cost[i][j] = INF;
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		cost[a][b] = c;
	}

	FOR(i, n){
		ll have = INF;
		FOR(j, 4*n){
			have++;
			cost[i][j%n] = std::min(cost[i][j%n], have);
			have = std::min(have, cost[i][j%n]);
		}
	}

	FOR(i, n) FOR(j, n) dist[i][j] = INF;

	FOR(i, n){
		dijkstra(i);
	}


	FOR(i, n){
		FOR(j, n){
			std::cout << dist[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}