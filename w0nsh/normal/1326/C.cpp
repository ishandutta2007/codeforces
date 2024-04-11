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

const int MOD = 998244353;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<bool> block(n);
	ll ans1 = 0;
	FOR(i, n){
		if(A[i] > n-k) block[i] = true, ans1 += A[i];
	}
	int ans2 = 1;
	int last = -1;
	FOR(i, n){
		if(block[i]){
			if(last != -1) ans2 = (1ll*ans2*(i-last))%MOD;
			last = i;
		}
	}
	std::cout << ans1 << " " << ans2 << "\n";

	return 0;
}