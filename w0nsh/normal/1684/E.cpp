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
	int n, k;
	std::cin >> n >> k;
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}

	std::set<PII> set;
	for(auto [x, cnt]: map){
		set.insert(MP(cnt, x));
	}

	std::set<PII> taken;

	int have = k;

	auto dodaj = [&]{
		auto it = set.begin();
		while(it != set.end() && it->X <= have){
			have -= it->X;
			taken.insert(*it);
			auto next = std::next(it);
			set.erase(it);
			it = next;
		}
	};

	dodaj();

	int ans = SZ(set);
	int need = 0;
	REP(mex, 1, n+1){
		if(map.count(mex-1) == 0){
			need++;
		}
		if(need > k) break;
		if(taken.count(MP(map[mex-1], mex-1))){
			taken.erase(MP(map[mex-1], mex-1));
			have += map[mex-1];
			dodaj();
		}else{
			set.erase(MP(map[mex-1], mex-1));
		}

		ans = std::min(ans, SZ(set));
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}