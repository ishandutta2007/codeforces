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

int n, k;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	if(n < k){
		std::cout << "NO\n";
		return 0;
	}
	std::multiset<int> have;
	FOR(i, 31){
		if(n&(1<<i)) have.insert(1<<i);
	}
	if(SZ(have) > k){
		std::cout << "NO\n";
		return 0;
	}
	while(SZ(have) < k){
		auto it = std::next(have.end(), -1);
		int what = *it;
		have.erase(it);
		have.insert(what/2);
		have.insert(what/2);
	}
	std::cout << "YES\n";
	TRAV(i, have) std::cout << i << " ";
	return 0;
}