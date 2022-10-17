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
	VI A;
	int d;

	A.resize(3);
	FOR(i, 3) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	std::cin >> d;
	std::cout << std::max(0ll, 1ll*d-(1ll*A[1]-1ll*A[0])) + std::max(0ll, 1ll*d-(1ll*A[2]-1ll*A[1]));
	return 0;
}