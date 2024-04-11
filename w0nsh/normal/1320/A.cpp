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
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<VI> xd;
	std::map<int, VI> map;
	FOR(i, n) map[A[i]-i].push_back(i);
	ll best = 0;
	TRAV(pr, map){
	ll cand = 0;
		TRAV(j, pr.Y)  cand += A[j];
		best = std::max(best, cand);
	}
	std::cout << best;

	return 0;
}