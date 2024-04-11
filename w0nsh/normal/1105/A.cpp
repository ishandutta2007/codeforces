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
	VI A;
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int best = 1000000000;
	int bt = -1;
	REP(t, 1, 102){
		int cur = 0;
		TRAV(i, A){
			if(i > t) cur += i-t-1;
			else if(i < t) cur += t-i-1;
		}
		if(cur < best) bt = t, best = cur;
	}
	std::cout << bt << " " <<  best;
	return 0;
}