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
	int n;
	std::cin >> n;
	std::vector<ll> A(n), B(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];
	FOR(i, n){
		A[i] *= 1ll*(n-i)*(i+1);
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::reverse(B.begin(), B.end());
	int ans = 0;
	FOR(i, n) ans = (1ll*ans + (A[i]%MOD)*(B[i]%MOD))%MOD;
	std::cout << ans;
	return 0;
}