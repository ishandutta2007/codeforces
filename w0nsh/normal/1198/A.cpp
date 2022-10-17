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
	int n, I;
	std::cin >> n >> I;
	I *= 8;
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}
	VI A;
	TRAV(pr, map) A.push_back(pr.Y);
	VI pref, suf;
	pref.push_back(0);
	FOR(i, SZ(A)) pref.push_back(pref.back()+A[i]);
	suf.resize(SZ(A)+1);
	suf[SZ(A)] = 0;
	for(int i = SZ(A)-1; i >= 0; --i) suf[i] = suf[i+1] + A[i];
	int moge = 0;
	while(1ll*(moge+1)*n <= I) moge++;
	if(moge > 30 || (1<<moge) >= SZ(map)){
		std::cout << 0 << "\n";
		return 0;
	}
	moge = 1<<moge;
	int best = n;
	int dl = SZ(map)-moge;
	FOR(i, dl+1){
		best = std::min(best, pref[i]+suf[SZ(A)-(dl-i)]);
	}
	std::cout << best;
	return 0;
}