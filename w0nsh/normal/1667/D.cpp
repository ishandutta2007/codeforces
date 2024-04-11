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

void solve(){
	int n;
	std::cin >> n;
	std::vector<std::vector<PII>> g(n);
	std::vector<VI> order(n-1);
	std::vector<PII> edges(n-1);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(MP(b, i));
		g[b].push_back(MP(a, i));
		edges[i] = MP(a, b);
	}

	bool bad = false;

	// 0 - od razu, 1 - po jednym
	std::function<int(int, int)> dfs = [&](int v, int par){
		std::vector<std::vector<PII>> vec(2);
		for(auto[ch, ind] : g[v]) {
			if(ind == par) continue;
			int jak = dfs(ch, ind);
			if(bad) return -1;
			int xd = ((SZ(g[ch]) + SZ(g[v]) - 2) & 1) ^ jak;
			vec[xd].push_back(MP(jak, ind));
		}

		if(par == -1){
			if(SZ(vec[1]) == SZ(vec[0]) || SZ(vec[1]) == SZ(vec[0]) - 1){
				int co = 0;
				int last = -1;
				while(SZ(vec[co])){
					auto [jak, ind] = vec[co].back();
					vec[co].pop_back();
					co ^= 1;
					if(last != -1){
						order[last].push_back(ind);
					}
					last = ind;
				}

				assert(vec[0].empty() && vec[1].empty());
				return 0;
			}
			bad = true;
			return -1;
		}

		if(SZ(vec[1]) == SZ(vec[0]) || SZ(vec[1]) == SZ(vec[0]) + 1){
			int last = par;
			int co = 1;
			while(SZ(vec[co])){
				auto [jak, ind] = vec[co].back();
				vec[co].pop_back();
				co ^= 1;

				order[last].push_back(ind);
				last = ind;
			}

			assert(vec[0].empty() && vec[1].empty());
			return 0;
		}else if(SZ(vec[1]) == SZ(vec[0]) - 1 || SZ(vec[1]) == SZ(vec[0]) - 2) {
			int last = vec[0].back().Y;
			vec[0].pop_back();
			order[last].push_back(par);
			last = par;

			int co = 0;
			while(SZ(vec[co])){
				auto [jak, ind] = vec[co].back();
				vec[co].pop_back();
				co ^= 1;

				order[last].push_back(ind);
				last = ind;
			}

			return 1;
			assert(vec[0].empty() && vec[1].empty());
		}

		bad = true;
		return -1;
	};

	dfs(0, -1);
	if(bad){
		std::cout <<"NO\n";
		return;
	}

	std::vector<int> vis(n-1);
	VI topo;
	std::function<void(int)> elo = [&](int v){
		vis[v] = 1;
		TRAV(ch, order[v]){
			if(vis[ch] == 2) continue;
			assert(vis[ch] != 1);
			elo(ch);
		}
		vis[v] = 2;
		topo.push_back(v);
	};
	FOR(i, n-1) if(!vis[i]) elo(i);

	std::reverse(topo.begin(), topo.end());
	std::cout << "YES\n";
	TRAV(i, topo){
		std::cout << edges[i].X+1 << " " << edges[i].Y + 1 << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}