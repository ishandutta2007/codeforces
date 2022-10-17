#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, d, m;
	std::cin >> n >> d >> m;
	VI A, B;
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a > m) B.push_back(a);
		else A.push_back(a);
	}

	std::sort(B.begin(), B.end());
	std::sort(A.begin(), A.end());

	ll ans = 0;
	if(SZ(B) == 0){
		TRAV(i, A) ans += i;
	}else{
		std::vector<ll> pref(SZ(A)+1);
		REP(i, 1, SZ(A)+1) pref[i] = pref[i-1] + A[i-1];
		
		ll from = 0;
		REP(i, 1, SZ(B)+1){
			from += B[SZ(B)-i];

			ll need = 1ll*d*(i-1);
			if(need > n-i) continue;
			int other = SZ(B)-i;
			need -= other;

			need = std::max(need, 0ll);

			ll cur = from + pref[SZ(A)]-pref[need];
			ans = std::max(cur, ans);
		}
	}
	
	std::cout << ans << "\n";

	return 0;
}