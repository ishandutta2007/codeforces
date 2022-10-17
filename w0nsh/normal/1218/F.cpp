#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	int n, k;
	std::cin >> n >> k;
	VI X(n);
	FOR(i, n){
		std::cin >> X[i];
	}
	int A;
	std::cin >> A;
	VI C(n);
	FOR(i, n){
		std::cin >> C[i];
	}
	ll ans = 0;
	std::multiset<int> have;
	int h = 0;
	FOR(i, n){
		have.insert(C[i]);
		int need = (X[i]-k)/A;
		if((X[i]-k)%A != 0) need++;
		if(X[i] <= k) need = 0;
		while(h < need && SZ(have)){
			auto it = have.begin();
			ans += *it;
			have.erase(it);
			h++;
		}
		if(h < need){
			std::cout << -1 << "\n";
			return 0;
		}
	}
	std::cout << ans << "\n";

	return 0;
}