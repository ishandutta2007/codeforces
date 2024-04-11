#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m;
int tab[4][105];

std::vector<VI> where;
void rec(VI v, int a){
	if(a == n-1){
		FOR(i, n-1){
			v.push_back(v[i]);
			where.push_back(v);
			v.pop_back();
		}
		return;
	}
	FOR(i, m){
		v.push_back(i);
		rec(v, a+1);
		v.pop_back();
	}
}

int nt[4][105];

int get(VI kto, int ind){
	int best = 0;
	FOR(i, n){
		int cur = 0;
		TRAV(j, kto) cur += nt[(j+i)%n][ind];
		best = std::max(best, cur);
	}
	return best;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		FOR(i, n){
			FOR(j, m) std::cin >> tab[i][j];
		}
		VI big;
		FOR(j, m){
			int max = 0;
			FOR(i, n) max = std::max(max, tab[i][j]);
			big.push_back(max);
		}
		std::sort(big.begin(), big.end());
		int ans = 0;
		FOR(i, n){
			if(big.empty()) break;
			ans += big.back();
			big.pop_back();
		}
		if(n == 1){
			std::cout << ans << "\n";
			continue;
		}
		std::vector<PR<int, PII> > aaa;
		FOR(i, n){
			FOR(j, m){
				aaa.push_back(MP(tab[i][j], MP(i, j)));
			}
		}
		std::sort(aaa.begin(), aaa.end());
		std::set<int> alive;
		FOR(i, std::min(17, (int)SZ(aaa))){
			alive.insert(aaa.back().Y.Y);
			aaa.pop_back();
		}
		int ind = 0;
		FOR(i, m){
			if(alive.count(i)){
				FOR(j, n) nt[j][ind] = tab[j][i];
				ind++;
			}
		}
		m = ind;
		where.clear();
		rec(VI(), 0);
		std::map<int, VI> map;
		TRAV(v, where){
			FOR(i, n) map[v[i]].push_back(i);
			int cur = 0;
			TRAV(i, map) cur += get(i.Y, i.X);
			ans = std::max(ans, cur);
			map.clear();
		}
		std::cout << ans << "\n";
	}

	return 0;
}