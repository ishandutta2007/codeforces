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

int n[2], temp, best;
std::map<int, int> rest;
VI pos[2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 2){
		std::cin >> n[i] >> temp;
		pos[i].resize(n[i]);
		FOR(j, n[i]) std::cin >> pos[i][j];
	}
	best = 2;
	for(int pow = 1; pow < 1000000000; pow<<=1){
		rest.clear();
		FOR(i, n[0]) rest[pos[0][i]%(2*pow)]++;
		FOR(i, n[1]) rest[(pos[1][i]+pow)%(2*pow)]++;
		TRAV(pr, rest){
			best = std::max(pr.Y, best);
		}
	}
	std::cout << best << "\n";
	return 0;
}