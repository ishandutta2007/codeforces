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
	int q;
	std::cin >> q;
	FOR(_, q){
		int n;
		std::cin >> n;
		std::multiset<int> set;
		FOR(i, n){
			int a;
			std::cin >> a;
			set.insert(a);
		}
		if(n == 1){
			if(*set.begin() == 2048) std::cout << "YES\n";
			else std::cout << "NO\n";
			continue;
		}
		while(SZ(set) > 1){
			auto it = set.begin();
			auto next = std::next(it, 1);
			if(*it >= 2048) break;
			if(*it !=  *next){
				set.erase(it);
			}else{
				int xd = (*it) *2;
				set.erase(it);
				set.erase(set.begin());
				set.insert(xd);
			}
		}
		if(*set.begin() == 2048) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
	return 0;
}