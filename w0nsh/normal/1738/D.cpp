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
	int n;
	std::cin >> n;
	VI B(n+1);
	FOR(i, n) std::cin >> B[i+1];

	int mn = 0;
	int mx = n;
	REP(i, 1, n+1){
		assert(i != B[i]);
		if(B[i] < i){
			mx = std::min(mx, i-1);
		}else{
			mn = std::max(mn, i);
		}
	}
	assert(mn == mx);
	int k = mn;

	VI par(n+1);
	std::map<int, VI> map;
	REP(i, 1, n+1){
		if(B[i] == 0 || B[i] == n+1) par[i] = 0, map[0].push_back(i);
		else par[i] = B[i], map[B[i]].push_back(i);
	}

	int cur = 0;
	VI ret;
	while(true){
		auto& vec = map[cur];
		int kt = -1;
		TRAV(i, vec){
			if(map.count(i)){
				assert(kt == -1);
				kt = i;
			}
		}
		if(kt == -1){
			TRAV(i, vec) ret.push_back(i);
			assert(SZ(ret) == n);
			break;
		}else{
			TRAV(i, vec) if(i != kt) ret.push_back(i);
			ret.push_back(kt);
			cur = kt;
		}
	}

	std::cout << k << "\n";
	TRAV(i, ret) std::cout << i << " ";
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}