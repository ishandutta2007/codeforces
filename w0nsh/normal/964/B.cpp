#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, A, B, C, T;
VI vec;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> A >> B >> C >> T;
	vec.resize(n);
	FOR(i, n) std::cin >> vec[i];
	if(B >= C){
		std::cout << n*A << "\n";
	}else{
		ll ans = n*A;
		FOR(i, n) ans += (T-vec[i])*C;
		FOR(i, n) ans -= (T-vec[i])*B;
		std::cout << ans << "\n";
	}
	return 0;
}