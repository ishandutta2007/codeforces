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
	int t;
	std::cin >> t;
	while(t--){
		int n, m, k;
		std::cin >> n >> m >> k;

		std::deque<int> cards;
		FOR(i, m) cards.push_back(1);
		FOR(i, n-m) cards.push_back(0);

		VI mam(k);
		while(SZ(cards) > 0){
			mam[0] += cards.front();
			cards.pop_front();
			REP(i, 1, k){
				mam[i] += cards.back();
				cards.pop_back();
			}
		}
		std::cout << mam[0] - *std::max_element(mam.begin()+1, mam.end()) << "\n";
	}

	return 0;
}