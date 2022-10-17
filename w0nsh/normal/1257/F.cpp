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
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::map<VI, int> map;
	FOR(mask, 1<<15){
		VI vec(n);
		FOR(i, n){
			int xd = (A[i]>>15) & ((1<<15)-1);
			xd ^= mask;
			vec[i] = __builtin_popcount(xd);
		}
		int sub = vec[0];
		FOR(i, n) vec[i] -= sub;
		map[vec] = mask;
	}
	FOR(mask, 1<<15){
		VI vec(n);
		FOR(i, n){
			int xd = A[i] & ((1<<15)-1);
			xd ^= mask;
			vec[i] = __builtin_popcount(xd);
		}
		int sub = vec[0];
		FOR(i, n) vec[i] -= sub;
		FOR(i, n) vec[i] = -vec[i];
		auto it = map.find(vec);
		if(it != map.end()){
			std::cout << mask + (it->Y << 15) << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
	return 0;
}