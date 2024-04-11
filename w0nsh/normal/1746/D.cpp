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

using PLL = PR<ll, ll>;

void solve(){
	int n, k;
	std::cin >> n >> k;
	std::vector<VI> g(n);
	FOR(i, n-1){
		int p;
		std::cin >> p;
		p--;
		g[p].push_back(i+1);
	}

	std::vector<ll> S(n);
	FOR(i, n) std::cin >> S[i];

	std::function<PLL(int, int)> fun = [&](int v, int ile){
		if(SZ(g[v]) == 0){
			return MP(1ll * ile * S[v], 1ll * S[v]);
		}

		int base = ile / SZ(g[v]);
		int left = ile % SZ(g[v]);
		ll ret = 0;
		std::vector<ll> vec;
		TRAV(ch, g[v]){
			auto xd = fun(ch, base);
			vec.push_back(xd.Y);
			ret += xd.X;
		}
		std::sort(vec.begin(), vec.end());
		FOR(_, left) ret += vec.back(), vec.pop_back();

		return MP(ret + 1ll * ile * S[v], 1ll * S[v] + vec.back());
	};

	std::cout << fun(0, k).X << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}