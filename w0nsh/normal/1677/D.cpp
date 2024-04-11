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

int solve(){
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<PII> range(n);
	FOR(i, k) range[i] = MP(0, i);
	FOR(i, n){
		if(A[i] > i) return 0;
		if(A[i] > 0 && i + k >= n) return 0;
		if(i + k < n){
			if(A[i] > 0){
				range[i + k] = MP(A[i] + k, A[i] + k);
			}else if(A[i] == 0){
				range[i + k] = MP(0, k);
			}else{
				range[i + k] = MP(0, i + k);
			}
		}
	}

	// FOR(i, n) std::cerr << range[i].X << " " << range[i].Y << std::endl;

	int ans = 1;
	FOR(i, n) ans = (1ll * ans * (range[i].Y - range[i].X + 1)) % MOD;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) std::cout << solve() << "\n";

	return 0;
}