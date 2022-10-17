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
	std::map<PII, std::vector<PII> > map;
	std::cin >> n;
	FOR(i, n){
		int a, b, c;
		std::cin >> a >> b >> c;
		map[MP(a, b)].push_back(MP(c, i+1));
	}
	std::map<int, std::vector<PII> > A;
	TRAV(pr, map){
		std::sort(pr.Y.begin(), pr.Y.end());
		while(SZ(pr.Y) > 1){
			std::cout << pr.Y.back().Y << " " << pr.Y[SZ(pr.Y)-2].Y << "\n";
			pr.Y.pop_back();
			pr.Y.pop_back();
		}
		if(SZ(pr.Y) == 1) A[pr.X.X].push_back(MP(pr.X.Y, pr.Y[0].Y));
	}
	std::vector<PII> xd;
	TRAV(pr, A){
		std::sort(pr.Y.begin(), pr.Y.end());
		while(SZ(pr.Y) > 1){
			std::cout << pr.Y.back().Y << " " << pr.Y[SZ(pr.Y)-2].Y << "\n";
			pr.Y.pop_back();
			pr.Y.pop_back();
		}
		if(SZ(pr.Y) == 1) xd.push_back(MP(pr.X, pr.Y[0].Y));
	}
	std::sort(xd.begin(), xd.end());
	for(int i = 0; i < SZ(xd); i += 2) std::cout << xd[i].Y << " " << xd[i+1].Y << "\n";
	return 0;
}