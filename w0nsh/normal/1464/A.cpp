#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		
		VI repr(n);
		FOR(i, n) repr[i] = i;

		std::function<int(int)> Find = [&](int a){
			if(a == repr[a]) return a;
			return repr[a] = Find(repr[a]);
		};
		auto Union = [&](int a, int b){
			repr[Find(a)] = Find(b);
		};

		VI deg(n);
		int ans = m;
		FOR(i, m){
			int x, y;
			std::cin >> x >> y;
			x--;y--;
			Union(x, y);
			deg[x]++;
			if(x != y) deg[y]++;
			else ans--;
		}

		std::vector<VI> g(n);
		FOR(i, n) g[Find(i)].push_back(i);
		FOR(i, n){
			bool all2 = true;
			TRAV(ch, g[i]) if(deg[ch] < 2) all2 = false;
			if(all2 && SZ(g[i]) > 1) ans++;
		}
		std::cout << ans << "\n";
	}

	return 0;
}