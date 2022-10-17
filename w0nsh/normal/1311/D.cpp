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
	std::vector<PR<PII, int> > vec;
	int MX = 30005;
	REP(i, 1, MX){
		for(int j = i; j < MX; j += i){
			for(int k = j; k < MX; k += j){
				vec.push_back(MP(MP(i, j), k));
			}
		}
	}
	int t;
	std::cin >> t;
	while(t--){
		int a, b, c;
		std::cin >> a >> b >> c;
		int best = 1000000;
		PR<PII, int> ans;
		TRAV(i, vec){
			int cand = std::abs(a-i.X.X)+std::abs(b-i.X.Y)+std::abs(c-i.Y);
			if(cand < best){
				best = cand;
				ans = i;
			}
		}
		std::cout << best << "\n";
		std::cout << ans.X.X << " " << ans.X.Y << " " << ans.Y << "\n";
	}
	return 0;
}