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

const int MOD = 1000000007;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	VI fib(100005);
	fib[0] = 1;
	fib[1] = 1;
	REP(i, 2, 100005) fib[i] = (fib[i-1]+fib[i-2])%MOD;
	int ans = (2ll*fib[n]+2ll*fib[m]-2ll)%MOD;
	if(ans < 0) ans += MOD;
	std::cout << ans;
	return 0;
}