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

constexpr ll INF = 1000000666ll*10000000ll;
ll dist[505][505];
ll edge[505][505];
ll can[505][505];

void solve(){
	int n, m;
	std::cin >> n >> m;

	FOR(i, n) FOR(j, n) dist[i][j] = INF, edge[i][j] = INF, can[i][j] = INF;
	FOR(i, n) dist[i][i] = 0, can[i][i] = 0, edge[i][i] = 0;

	FOR(i, m){
		int a, b, w;
		std::cin >> a >> b >> w;
		a--;b--;
		can[a][b] = can[b][a] = 1;
		edge[a][b] = edge[b][a] = std::min(edge[a][b], 1ll * w);
		dist[a][b] = dist[b][a] = edge[a][b];
	}

	FOR(k, n){
		FOR(i, n){
			FOR(j, n){
				can[i][j] = std::min(can[i][j], can[i][k] + can[k][j]);
			}
		}
	}

	ll ans = INF;
	FOR(i, n){
		FOR(j, n){
			if(i == j) continue;

			if(edge[i][j] < INF){
				ans = std::min(ans, edge[i][j] * (1 + std::min(can[0][i] + can[j][n-1], can[0][j] + can[i][n-1])));

			}
		}
	}

	FOR(i, n){
		ll mn = INF;
		FOR(j, n) if(i != j) mn = std::min(mn, edge[i][j]);
		if(mn < INF){
			FOR(k, n){
				ans = std::min(ans, mn * (2 + can[0][k] + can[k][n-1] + can[i][k]));
			}
		}
	}
	
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}