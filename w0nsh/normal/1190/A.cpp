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
	ll n, m, k;
	std::cin >> n >> m >> k;
	std::vector<ll> A(m);
	FOR(i, m){
		std::cin >> A[i];
		A[i]--;
	}
	int dels = 0;
	int ans = 0;
	int pos = 0;
	while(pos < m){
		int last = pos;
		ll ind = (A[pos]-dels)/k;
		while(pos < m && (A[pos]-dels)/k == ind) pos++;
		dels += pos-last;
		ans++;
	}
	std::cout << ans;
	return 0;
}