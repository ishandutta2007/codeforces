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

typedef std::array<int, 5> AR;

void solve(){
	int n;
	std::cin >> n;
	std::vector<AR> A(n);
	FOR(i, n){
		FOR(j, 5) std::cin >> A[i][j];
	}

	FOR(a, 5){
		REP(b, a+1, 5){
			int fs = 0;
			int sc = 0;
			int both = 0;
			bool bad = false;
			FOR(i, n){
				if(A[i][a] && A[i][b]) both++;
				else if(A[i][a]) fs++;
				else if(A[i][b]) sc++;
				else bad = true;
			}
			if(bad) continue;

			if(std::min(fs, sc) + both >= std::max(fs, sc)){
				std::cout << "YES\n";
				return;
			}
		}
	}

	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}