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
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];
	int x;
	std::cin >> x;

	FOR(i, n) A[i+1] -= x;
	std::vector<ll> pref(n+1);
	REP(i, 1, n+1) pref[i] = pref[i-1] + A[i];

	constexpr ll INF = 1000000000ll*10000000ll;
	ll mx = -INF;
	int pos = 1;
	int ans = 0;
	while(pos <= n){
		if(pref[pos] < mx){
			mx = -INF;
			pos++;
		}else{
			mx = std::max(pref[pos-1], mx);
			pos++;
			ans++;
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