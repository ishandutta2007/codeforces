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
	while(q--){
		int n;
		std::cin >> n;
		std::map<int, int> map;
		FOR(i, n){
			int a;
			std::cin >> a;
			map[a]++;
		}
		VI have;
		TRAV(i, map) have.push_back(i.Y);
		std::sort(have.begin(), have.end());
		std::set<int> pos;
		FOR(i, n) pos.insert(i+1);
		int ans = 0;
		TRAV(i, have){
			auto it = pos.upper_bound(i);
			if(it == pos.begin()) continue;
			it--;
			ans += *it;
			pos.erase(it);
		}
		std::cout << ans << "\n";
	}
	return 0;
}