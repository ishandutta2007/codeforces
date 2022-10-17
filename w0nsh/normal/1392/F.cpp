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
	int n;
	std::cin >> n;
	ll sum = 0;
	FOR(i, n){
		ll a;
		std::cin >> a;
		sum += a;
	}

	ll xd = 1ll*n*(n-1)/2;
	ll more = sum-xd;
	ll add = more/n;
	std::vector<ll> ans(n);
	FOR(i, n) ans[i] = add+i;
	more %= n;
	FOR(i, n){
		if(more > 0) ans[i]++, more--;
	}

	FOR(i, n) std::cout << ans[i] << " ";





	return 0;
}