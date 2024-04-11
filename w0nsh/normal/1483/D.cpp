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

constexpr ll INF = 1000000666ll*1000000666ll;

ll dist[605][605];
ll edge[605][605];
ll jez[605][605];
bool good[605][605];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	
	FOR(i, n) FOR(j, n) dist[i][j] = INF, edge[i][j] = INF;
	FOR(i, n) dist[i][i] = 0;

	FOR(i, m){
		ll u, v, w;
		std::cin >> u >> v >> w;
		u--;v--;
		edge[u][v] = edge[v][u] = w;
		dist[u][v] = dist[v][u] = w;
	}

	FOR(k, n){
		FOR(i, n){
			FOR(j, n){
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int q;
	std::cin >> q;

	FOR(i, n) FOR(j, n) jez[i][j] = -1;

	FOR(_, q){
		ll u, v, l;
		std::cin >> u >> v >> l;
		u--;v--;
		FOR(i, n){
			jez[u][i] = std::max(jez[u][i], l - dist[v][i]);
			jez[v][i] = std::max(jez[v][i], l - dist[u][i]);
		}
	}

	int ans = 0;
	FOR(i, n){
		FOR(j, n){
			if(edge[i][j] == INF) continue;
			FOR(fs, n){
				ll ds = edge[i][j] + dist[fs][i];
				ll heh = jez[fs][j] - ds;
				if(heh >= 0){
					if(!good[i][j] && !good[j][i]){
						ans++;
						// std::cout << "ide z " << fs << " do " << i << " potem " << j << std::endl;
						// std::cout << "ds = " << edge[i][j] << " + " << dist[fs][i] << " jez " << jez[fs][j] << std::endl;
						// std::cout << "good " << i << " " << j << std::endl;
						good[i][j] = true;
						good[j][i] = true;
					}
				}
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}