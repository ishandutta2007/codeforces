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
	int n, x;
	std::cin >> n >> x;
	std::vector<ll> A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<ll> B(n);
	FOR(i, n) B[i] = A[i]*x;
	std::vector<ll> left(n), right(n);
	ll have = 0;
	FOR(i, n){
		have += A[i];
		if(have < 0) have = 0;
		left[i] = have;
	}
	have = 0;
	for(int i = n-1; i >= 0; --i){
		have += A[i];
		if(have < 0) have = 0;
		right[i] = have;
	}
	ll best = 0;
	have = 0;
	ll ans = 0;
	FOR(i, n){
		have += B[i];
		ll cur = have;
		if(i < n-1) cur += right[i+1];
		best = std::max(best, -have+left[i]);
		ans = std::max(ans, cur+best);
	}
	std::cout << ans;
	return 0;
}