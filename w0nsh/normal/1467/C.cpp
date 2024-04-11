#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
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

	VI ile(3);
	FOR(i, 3) std::cin >> ile[i];
	VI A;
	std::vector<ll> sum(3);
	std::vector<ll> min(3, 1000000666ll);
	FOR(j, 3){
		FOR(i, ile[j]){
			int a;
			std::cin >> a;
			sum[j] += a;
			min[j] = std::min(min[j], 1ll*a);
		}
	}
	ll ans = 0;
	FOR(i, 3){
		REP(j, i+1, 3){
			ans = std::max(ans, sum[0] + sum[1] + sum[2] - 2 * (min[i] + min[j]));
		}
	}
	FOR(i, 3) ans = std::max(ans, sum[0]+sum[1]+sum[2]-2ll*sum[i]);
	std::cout <<ans;

	return 0;
}