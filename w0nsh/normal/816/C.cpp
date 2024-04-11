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

int n, m;
int tab[105][105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n) FOR(j, m) std::cin >> tab[i][j];
	int best = 1000000666;
	VI br, bc;
	FOR(k, tab[0][0]+1){
		VI rows(n, -1), cols(m, -1);
		rows[0] = k;
		bool bad = false;
		FOR(i, m){
			cols[i] = tab[0][i]-k;
			if(cols[i] < 0) bad = true;
		}
		FOR(i, n){
			rows[i] = tab[i][0]-cols[0];
			if(rows[i] <  0) bad = true;
		}
		if(bad) continue;
		FOR(i, n){
			FOR(j, m) if(tab[i][j] != rows[i] + cols[j]){
				bad = true;
				break;
			}
			if(bad) break;
		}
		if(!bad){
			int cur = 0;
			TRAV(i, rows) cur += i;
			TRAV(i, cols) cur += i;
			if(cur < best){
				best = cur;
				br = rows;
				bc = cols;
			}
		}
	}
	if(best == 1000000666) std::cout << -1;
	else{
		std::cout << best << "\n";
		FOR(i, n){
			while(br[i] > 0) br[i]--, std::cout << "row " << i+1 << "\n";
		}
		FOR(i, m){
			while(bc[i] > 0) bc[i]--, std::cout << "col " << i+1 << "\n";
		}

	}
	return 0;
}