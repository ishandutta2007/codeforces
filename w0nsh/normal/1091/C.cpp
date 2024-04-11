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

int n;
VI dv;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 1; i*i <= n; ++i){
		if(n%i == 0){
			dv.push_back(i);
			if(i*i != n) dv.push_back(n/i);
		}
	}
	std::sort(dv.begin(), dv.end());
	std::reverse(dv.begin(), dv.end());
	TRAV(d, dv){
		int ile = n/d;
		ll arytsum = 1ll*ile*(ile+1)/2ll;
		arytsum *= d;
		arytsum -= 1ll*(d-1)*ile;
		std::cout << arytsum << " ";
	}
	return 0;
}