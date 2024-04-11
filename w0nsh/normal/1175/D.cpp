#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	std::vector<ll> pref(n+1);
	for(int i = n-1; i >= 0; --i) pref[i] = pref[i+1] + A[i];
	ll ans = pref[0];
	pref.pop_back();
	std::swap(pref.back(), pref[0]);
	pref.pop_back();
	std::sort(pref.begin(), pref.end(), std::greater<ll>());
	FOR(i, k-1) ans += pref[i];
	std::cout << ans;
	return 0;
}