#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	int n;
	std::vector<PII> A;
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i].X, A[i].Y = i;
	std::sort(A.begin(), A.end());
	std::reverse(A.begin(), A.end());
	ll ans = 0;
	FOR(i, n){
		ans += A[i].X*i+1;
	}
	std::cout << ans << "\n";
	TRAV(i, A) std::cout << i.Y+1 << " ";
	return 0;
}