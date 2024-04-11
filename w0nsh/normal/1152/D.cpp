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
PII mem[2005][2005];
// (z krawe)

PII ans(int k, int n){
	// std::cout << k << ", " << n << std::endl;
	if(mem[k][n].X != -1) return mem[k][n];
	if(n == 0 && k == 0) return MP(0, 0); 
	if(k == 0){
		auto rg = ans(k+1, n-1);
		return MP(std::max(rg.X, rg.Y), (rg.X+1)%MOD);
	}
	if(k+1 > n-1){
		auto lf = ans(k-1, n-1);
		return MP(std::max(lf.X, lf.Y), (lf.X+1)%MOD);
	}
	auto lf = ans(k+1, n-1);
	auto rg = ans(k-1, n-1);
	return mem[k][n] = MP((std::max(lf.X, lf.Y)+std::max(rg.X, rg.Y))%MOD, std::max((lf.Y+rg.X+1)%MOD, (lf.X+rg.Y+1)%MOD));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 2005) FOR(j, 2005) mem[i][j] = MP(-1, 420);
	int n;
	std::cin >> n;
	n *= 2;
	auto xd = ans(0, n);
	std::cout << std::max(xd.X, xd.Y);
	return 0;
}