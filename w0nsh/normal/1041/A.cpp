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
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int ans = 0;
	std::sort(A.begin(), A.end());
	if(n == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	FOR(i, n-1){
		ans += A[i+1]-A[i]-1;
	}
	std::cout << ans << "\n";
	return 0;
}