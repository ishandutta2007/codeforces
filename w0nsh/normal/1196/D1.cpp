#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int tab[3][3], prze[3][3];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		if(k == 1){
			std::cout << 0 << "\n";
			continue;
		}
		VI A(n);
		FOR(i, n){
			if(s[i] == 'R') A[i] = 0;
			if(s[i] == 'G') A[i] = 1;
			if(s[i] == 'B') A[i] = 2;
		}
		FOR(i, 3) FOR(j, 3) tab[i][j] = 0;
		FOR(i, k) tab[i%3][A[i]]++;
		int best = 1000000000;
		REP(i, k, n){
			FOR(j, 3){
				int cur = 0;
				FOR(l, 3){
					int need = (k-l)/3 + ((k-l)%3 == 0 ? 0 : 1);
					int have = tab[l][(j+l)%3];
					cur += need-have;
				}
				// std::cout << "pos " << i-k << "-" << i-1 << " cand " << cur << std::endl;
				best = std::min(best, cur);
			}
			FOR(j, 3) FOR(l, 3) prze[j][l] = tab[(j+1)%3][l];
			prze[2][A[i-k]]--;
			prze[(k-1)%3][A[i]]++;
			FOR(j, 3) FOR(l, 3) tab[j][l] = prze[j][l];
		}
		FOR(j, 3){
			int cur = 0;
			FOR(l, 3){
				int need = (k-l)/3 + ((k-l)%3 == 0 ? 0 : 1);
				int have = tab[l][(j+l)%3];
				cur += need-have;
			}
			best = std::min(best, cur);
		}
		std::cout << best << "\n";
	}
	return 0;
}