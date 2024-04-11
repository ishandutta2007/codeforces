#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<VI> g(n);
		FOR(i, n){
			int k;
			std::cin >> k;
			FOR(j, k){
				int a;
				std::cin >> a;
				a--;
				g[i].push_back(a);
			}
		}
		std::vector<bool> taken(n);
		int last = -1;
		FOR(i, n){
			bool good = false;
			TRAV(ch, g[i]) if(!taken[ch]){
				taken[ch] = true;
				good = true;
				break;
			}
			if(!good) last = i;
		}
		if(last == -1) std::cout << "OPTIMAL\n";
		else{
			std::cout << "IMPROVE\n";
			FOR(i, n) if(!taken[i]){
				std::cout << last+1 << " " << i+1 << "\n";
				break;
			}
		}
	}

	return 0;
}