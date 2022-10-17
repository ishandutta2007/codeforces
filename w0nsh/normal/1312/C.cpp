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
		int n, k;
		std::cin >> n >> k;
		bool good = true;
		std::set<int> need;
		FOR(i, n){
			ll a;
			std::cin >> a;
			int wut = 0;
			while(a != 0){
				if(a%k != 0){
					if(a%k != 1){
						good = false;
						break;
					}
					if(need.count(wut)){
						good = false;
						break;
					}
					need.insert(wut);
				}
				a /= k;
				wut++;
			}
		}
		if(good) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}