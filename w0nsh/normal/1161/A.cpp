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
	std::cin >>n >> k;
	VI A(k);
	VI first(n, k), last(n, -1);
	FOR(i, k) std::cin >> A[i], A[i]--;
	FOR(i, k){
		first[A[i]] = std::min(first[A[i]], i);
		last[A[i]] = i;
	}
	ll ans = 0;
	FOR(i, n){
		if(first[i] == k) ans++;
		if(i > 0 && first[i] > last[i-1]) ans++;
		if(i < n-1 && first[i] > last[i+1]) ans++;
	}
	std::cout << ans;


	return 0;
}