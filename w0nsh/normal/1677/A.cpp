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

int pref[5005][5005];
int suf[5005][5005];

void solve(){
	int n;
	std::cin >> n;
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];

	REP(i, 1, n+1){
		pref[i][0] = 0;
		REP(j, 1, n+1){
			pref[i][j] = pref[i][j-1] + (A[j] < i);
		}
		suf[i][n+1] = 0;
		for(int j = n; j >= 1; --j){
			suf[i][j] = suf[i][j+1] + (A[j] < i);
		}
	}

	ll ans = 0;
	REP(i, 1, n+1){
		REP(j, i+1, n+1){
			ans += 1ll * suf[A[i]][j + 1] * pref[A[j]][i - 1];
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