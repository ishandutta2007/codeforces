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


int query(std::vector<VI> &a, std::vector<VI> &b){
	int sa = 0, sb = 0;
	TRAV(i, a) sa += SZ(i);
	TRAV(i, b) sb += SZ(i);
	std::cout << sa << " " << sb << " ";
	TRAV(i, a) TRAV(j, i) std::cout << j+1 << " ";
	TRAV(i, b) TRAV(j, i) std::cout << j+1 << " ";
	std::cout << std::endl;
	int ans;
	std::cin >> ans;
	if(ans == -1)  std::exit(0);
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<VI> jeds, zers;
		jeds.emplace_back();
		zers.emplace_back();
		FOR(i, n/2) jeds.back().push_back(i);
		REP(i, n/2, n) zers.back().push_back(i);
		int mx = 0;
		while(true){
			mx = std::max(mx, query(jeds, zers));
			std::vector<VI> nj, nz;
			bool good = false;
			TRAV(vec, jeds){
				if(SZ(vec) > 1) good = true;
				nj.emplace_back();
				if(SZ(vec) > 1) nz.emplace_back();
				FOR(j, (SZ(vec)+1)/2) nj.back().push_back(vec[j]);
				if(SZ(vec) > 1){
					REP(j, (SZ(vec)+1)/2, SZ(vec)) nz.back().push_back(vec[j]);
				}
			}
			TRAV(vec, zers){
				if(SZ(vec) > 1) good = true;
				nz.emplace_back();
				if(SZ(vec) > 1) nj.emplace_back();
				FOR(j, (SZ(vec)+1)/2) nz.back().push_back(vec[j]);
				if(SZ(vec) > 1){
					REP(j, (SZ(vec)+1)/2, SZ(vec)) nj.back().push_back(vec[j]);
				}
			}
			if(!good) break;
			jeds = nj;
			zers = nz;
		}
		std::cout <<-1 << " " << mx << std::endl;
	}
	return 0;
}