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
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];
	VI pref(n+2);
	VI suf(n+2);
	REP(i, 1, n+1) pref[i] = pref[i-1]|A[i];
	for(int i = n; i >= 1; --i) suf[i] = suf[i+1]|A[i];
	PII best = MP(0, 1);
	REP(i, 1, n+1){
		int xd = pref[i-1]|suf[i+1];
		PII cand = MP((xd|A[i])-xd, i);
		best = std::max(best, cand);
	}
	std::cout << A[best.Y] << " ";
	REP(i, 1, n+1) if(i != best.Y) std::cout << A[i] << " ";
	return 0;
}