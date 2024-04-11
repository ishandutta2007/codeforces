#pragma GCC optimize "Ofast"
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

int two[100][100];
int tww[100][100];
int one[100];
constexpr int L = 60;
constexpr int MOD = 1000000007;

int mul(int a, int b, int c){
	return (1ll*(1ll*a*b)%MOD * c)%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<ll> A(n);
		FOR(i, n) std::cin >> A[i];
		FOR(b1, L){
			FOR(b2, L){
				one[b1] = 0;
				tww[b1][b2] = 0;
				two[b1][b2] = 0;
			}
		}
		FOR(i, n)
		FOR(b, L){
			if(A[i] & (1ll<<b)) one[b]++;
		}
		FOR(i, n)
		FOR(b1, L){
			REP(b2, b1, L){
				two[b1][b2] += (A[i] & (1ll<<b1)) && (A[i] & (1ll<<b2));
			}
		}

		int ans = 0;
		auto get = [&](int a, int b){
			return two[std::min(a, b)][std::max(a, b)];
		};
		FOR(i, L){
			FOR(j, L){
				int ile = 0;
				ile = (ile + mul(one[i], (one[i]-get(i, j)), one[j]))%MOD;
				ile = (ile + mul(one[i], get(i, j), n))%MOD;
				ans = (ans + mul(ile, (1ll<<i)%MOD, (1ll<<j)%MOD))%MOD;
			}
		}

		std::cout << ans << "\n";
	}

	return 0;
}