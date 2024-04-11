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

const int MOD = 998244353;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int w, h;
	std::cin >> w >> h;
	int ans = 1;
	FOR(i, w+h) ans = (ans*2)%MOD;
	std::cout << ans;
	return 0;
}