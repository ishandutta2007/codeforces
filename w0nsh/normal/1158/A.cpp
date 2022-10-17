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

int n, m;
VI A, B;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >>n >> m;
	A.resize(n);
	B.resize(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	if(*std::max_element(A.begin(), A.end()) > *std::min_element(B.begin(), B.end())){
		std::cout << -1;
		return 0;
	}
	ll ans = 0;
	REP(i, 1, m) ans += B[i];
	ans += A.back();
	if(A.back() != B[0]){
		ans += B[0];
		ans += 1ll*(m-1)*A[SZ(A)-2];
	}else{
		ans += 1ll*m*A[SZ(A)-2];
	}
	FOR(i, n-2) ans += 1ll*m*A[i];
	std::cout << ans;
	return 0;
}