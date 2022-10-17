#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
	VI A(6);
	FOR(i, 6) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	std::reverse(A.begin(), A.end());
	std::cin >> n;
	VI B(n);
	FOR(i, n) std::cin >> B[i];
	std::sort(B.begin(), B.end());
	VI inter;
	FOR(i, n){
		FOR(j, 6) inter.push_back(B[i]-A[j]);
	}
	std::sort(inter.begin(), inter.end());
	inter.resize(std::unique(inter.begin(), inter.end())-inter.begin());

	std::set<PR<int, int> > set;
	FOR(i, n){
		set.insert(MP(B[i]-A[0], i));
	}

	ll ans = 1000000000ll*10000ll;

	auto fix = [&](int x){
		auto it = set.begin();
		while(it->X < x){
			int v = it->Y;
			int good = -1;
			FOR(j, 6){
				if(B[v] - A[j] >= x){
					good = j;
					break;
				}
			}
			if(good == -1){
				std::cout << ans << "\n";
				std::exit(0);
			}
			set.erase(it);
			set.insert(MP(B[v]-A[good], v));
			it = set.begin();
		}
	};

	auto getans = [&]{
		auto it = std::prev(set.end());
		return (ll)(it->X - set.begin()->X);
	};

	TRAV(x, inter){
		fix(x);
		ans = std::min(ans, getans());
	}

	std::cout << ans << "\n";

	return 0;
}