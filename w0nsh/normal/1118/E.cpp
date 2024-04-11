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

int n, k;
std::set<PII> set;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	int have = 0;
	PII last = MP(-1, -1);
	std::vector<PII> vec;
	REP(s, 1, k){
		FOR(i, k){
			PII cur = MP(i, (i+s)%k);
			// if(cur.X == last.X || cur.Y == last.Y){
			// 	// std::cout << "WHOOPS xdd\n";
			// 	// std::cout << last.X << " " << last.Y << "\n";
			// 	// std::cout << cur.X << " " << cur.Y << "\n";
			// 	// return 0;
			// }
			// if(set.count(cur) != 0) std::cout << "WHOOPS\n";
			last = cur;
			// set.insert(cur);
			vec.push_back(cur);
			have++;
			if(have == n) break;
		}
		if(have == n) break;
	}
	if(have < n) std::cout << "NO\n";
	else{
		std::cout << "YES\n";
		TRAV(i, vec) std::cout << i.X+1 << " " << i.Y+1 << "\n";
	}
	return 0;
}