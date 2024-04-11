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
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::set<int> set;
	std::map<int, int> map;
	FOR(i, n) set.insert(A[i]);
	int fre = 0;
	TRAV(i, set) map[i] = fre++;
	TRAV(i, A) i = map[i];
	int best = 1000000000;
	VI cnt(n);
	TRAV(i, A) cnt[i]++;
	int need = 0;
	FOR(i, n) if(cnt[i] > 1) need++;
	if(need == 0){
		std::cout << 0 << "\n";
		return 0;
	}
	FOR(s, n){
		int pos = s;
		int nd = need;
		VI cn = cnt;
		while(pos < n && nd != 0){
			cn[A[pos]]--;
			if(cn[A[pos]] == 1) nd--;
			pos++;
		}
		if(nd == 0) best = std::min(best, pos-s);
	}
	std::cout << best << "\n";
	return 0;
}