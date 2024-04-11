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

int query(int x){
	std::cout << "? " << x+1 << std::endl;
	int a;
	std::cin >> a;
	a--;
	assert(a != -1);
	return a;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<bool> dead(n);
	VI ans(n, -1);

	int turn = 0;
	FOR(i, n){
		if(dead[i]) continue;

		int x = query(i);
		VI cyc{x};
		while(true){
			x = query(i);
			if(x == cyc[0]) break;
			cyc.push_back(x);
		}

		FOR(j, SZ(cyc)) ans[cyc[j]] = cyc[(j+1)%SZ(cyc)];

		turn += SZ(cyc)+1;
		TRAV(j, cyc) dead[j] = true;
	}

	std::cout << "!";
	FOR(i, n) std::cout << " " << ans[i]+1;
	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}