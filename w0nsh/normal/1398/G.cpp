#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int N = 200'005;
using BS = std::bitset<N>;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, x, y;
	std::cin >> n >> x >> y;
	VI A(n+1);
	FOR(i, n+1) std::cin >> A[i];

	BS bs;
	BS ret;
	for(int i = n; i >= 0; --i){
		ret |= (bs >> A[i]);
		bs[A[i]] = true;
	}

	constexpr int MX = 500'005;
	VI ans(MX, -1);
	REP(i, y+1, MX){
		if(i - y < N && ret[i - y]){
			for(int j = i; j < MX; j += i){
				ans[j] = i - y;
			}
		}
	}

	int q;
	std::cin >> q;

	FOR(i, q){
		int cur;
		std::cin >> cur;
		cur /= 2;
		std::cout << (cur >= SZ(ans) || ans[cur] == -1 ? -1 : ans[cur]*2+2*y) << " ";
	}

	return 0;
}