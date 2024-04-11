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

const int INF = 1000000000;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A;
	VI maxy;
	int good = 0;
	FOR(i, n){
		int l;
		std::cin >> l;
		A.emplace_back(MP(INF, -INF));
		int min = INF;
		bool gd = false;
		FOR(j, l){
			int a;
			std::cin >> a;
			min = std::min(min, a);
			if(min < a){
				gd = true;
			}
			A.back().X = std::min(A.back().X, a);
			A.back().Y = std::max(A.back().Y, a);
		}
		if(gd){
			good++;
			A.pop_back();
		}else maxy.push_back(A.back().Y);
	}
	std::sort(maxy.begin(), maxy.end());
	ll ans = 0;
	FOR(i, good) ans += n;
	FOR(i, n-good){
		ans += good;
		ans += maxy.end()-std::upper_bound(maxy.begin(), maxy.end(), A[i].X);
	}
	std::cout << ans << "\n";
	return 0;
}