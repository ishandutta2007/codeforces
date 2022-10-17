#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n, u, v;
	std::cin >> n >> u >> v;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int mx = 0;
	REP(i, 1, n){
		mx = std::max(mx, std::abs(A[i] - A[i-1]));
	}
	if(mx > 1){
		std::cout << 0 << "\n";
	}else if(mx == 1){
		std::cout << std::min(u, v) << "\n";
	}else{
		std::cout << std::min(u+v, v+v) << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}