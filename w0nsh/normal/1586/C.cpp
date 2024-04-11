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

	int n, m;
	std::cin >> n >> m;
	std::vector<VI> tab(n, VI(m));
	FOR(i, n){
		FOR(j, m){
			char a;
			std::cin >> a;
			tab[i][j] = (a == 'X' ? 1 : 0);
		}
	}

	std::vector<bool> bad(m);

	REP(i, 1, n){
		FOR(j, m-1){
			if(tab[i][j] && tab[i-1][j+1]){
				bad[j] = true;
			}
		}
	}

	std::set<int> set;
	FOR(i, m) if(bad[i]) set.insert(i);

	int q;
	std::cin >> q;
	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;

		if(a == b) std::cout << "YES\n";
		else{
			auto it = set.lower_bound(a);
			if(it != set.end() && *it < b){
				std::cout << "NO\n";
			}else{
				std::cout << "YES\n";
			}
		}
	}

	return 0;
}