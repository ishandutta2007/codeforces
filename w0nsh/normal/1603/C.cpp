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

constexpr int MOD = 998244353;

int lst[100005];

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<PR<int, int>> co;
	VI vals;
	co.push_back(MP(A.back(), 1));
	A.pop_back();
	int ans = 0;

	while(SZ(A)){
		int x = A.back();
		A.pop_back();

		vals.clear();
		// next.clear();
		vals.push_back(x);
		lst[x] = 1;
		for(auto[y, pr] : co){
			if(x > y){
				int heh = ((x + y - 1) / y);
				assert(heh > 1);
				int nw = x / heh;
				assert(nw >= 1);
				ans = (1ll * ans + 1ll * (1ll * pr * (heh-1) % MOD) * (SZ(A) + 1)) % MOD;
				vals.push_back(nw);
				lst[nw] += pr;
			}else{
				vals.push_back(x);
				lst[x] += pr;
			}
		}

		co.clear();
		TRAV(v, vals){
			if(lst[v]) co.push_back(MP(v, lst[v]));
			lst[v] = 0;
		}

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