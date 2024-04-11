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
#define ld long double

int n, k, m;
VI A;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> m;
	A.resize(n);
	ll sum = 0;
	FOR(i, n) std::cin >> A[i], sum += A[i];
	std::sort(A.begin(), A.end());
	ld best = 0;
	int ops = m;
	FOR(i, n){
		if(ops < 0) break;
		ll add = std::min(1ll*ops, 1ll*k*(n-i));
		best = std::max(best, ((ld)(add+sum))/(n-i));
		ops--;
		sum -= A[i];
	}
	std::cout << std::fixed << std::setprecision(20) << best << "\n";
	return 0;
}