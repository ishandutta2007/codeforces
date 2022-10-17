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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		std::vector<VI> g(n);
		FOR(i, n-1){
			int a;
			std::cin >> a;
			a--;
			g[i+1].push_back(a);
			g[a].push_back(i+1);
		}
		VI par(n);
		VI spec(n);
		std::function<PII(int, int)> dfs = [&](int v, int parent) {
			PII ret = MP(0, v);
			par[v] = parent;
			TRAV(ch, g[v]) if(ch != parent){
				auto they = dfs(ch, v);
				they.X++;
				ret = std::max(ret, they);
			}
			return ret;
		};

		auto pr = dfs(0, -1);
		int pos = pr.Y;
		int left = 0;
		while(pos != 0){
			spec[pos] = 1;
			pos = par[pos];
			left++;
		}
		spec[0] = 1;
		left++;

		 
		int need = k;
		VI path;
		std::function<void(int, int)> dfs2 = [&](int v, int parent) {
			path.push_back(v);
			need--;
			if(spec[v]) left--;

			if(need == 0){
				return;
			}

			int ind = -1;
			FOR(i, SZ(g[v])) if(g[v][i] != parent && spec[g[v][i]]) ind = i;
			if(ind != -1) std::swap(g[v][ind], g[v].back());

			bool was_spec = false;
			TRAV(ch, g[v]) if(ch != parent){
				if((need <= left) == (bool)spec[ch]) {
					if(spec[ch]) was_spec = true;
					dfs2(ch, v);
					if(need > 0){
						path.push_back(v);
					}else{
						return;
					}
				}
			}

			if(!was_spec && spec[g[v].back()] && parent != g[v].back()){
				dfs2(g[v].back(), v);
				assert(need == 0);
			}
		};

		dfs2(0, -1);

		std::cout << SZ(path)-1 << "\n";
		TRAV(i, path) std::cout << i+1 << " ";
		std::cout << "\n";
	}

	return 0;
}