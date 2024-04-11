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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, p;
	std::cin >> n >> p;
	REP(i, 1, 60){
		int what = n-i*p;
		if(what > 0){
			std::multiset<int> have;
			for(int j = 30; j >= 0; --j){
				if(what >= (1<<j)){
					have.insert(j);
					what -= (1<<j);
				}
			}
			while(SZ(have) < i){
				if(*std::prev(have.end()) > 0){
					int en = *std::prev(have.end());
					have.erase(std::prev(have.end()));
					have.insert(en-1);
					have.insert(en-1);
				}else{
					break;
				}
			}
			if(SZ(have) == i){
				std::cout << i << "\n";
				return 0;
			}
		}
	}
	std::cout << -1 << "\n";
	return 0;
}