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
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<VI> where(n+1);
	FOR(i, n) where[A[i]].push_back(i);
	int mx = 0;
	VI pos;
	FOR(i, n+1){
		mx = std::max(mx, SZ(where[i]));
		TRAV(j, where[i]) pos.push_back(j);
	}

	VI B(n, -1);
	FOR(i, n){
		B[pos[i]] = A[pos[(i+mx)%n]];
	}

	FOR(i, n) std::cout << B[i] << " ";
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	return 0;
}