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
	int n, k;
	std::cin >> n >> k;
	if(k <= (n+1)/2){
		FOR(i, n){
			FOR(j, n){
				bool co = false;
				if(i == j && i % 2 == 0 && k > 0) k--, co = true;
				std::cout << (co ? 'R' : '.');
			}
			std::cout << "\n";
		}
	}else{
		std::cout << "-1\n";
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