#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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

	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;

	std::sort(A.begin(), A.end());

	int cur = 1;
	ll ans = 0;
	REP(i, 1, n){
		if(A[i].X == A[i-1].X) cur++;
		else{
			ans += 1ll*cur*(cur-1)/2;
			cur = 1;
		}
	}
	ans += 1ll*cur*(cur-1)/2;

	cur = 1;
	FOR(i, n) std::swap(A[i].X, A[i].Y);
	std::sort(A.begin(), A.end());

	REP(i, 1, n){
		if(A[i].X == A[i-1].X) cur++;
		else{
			ans += 1ll*cur*(cur-1)/2;
			cur = 1;
		}
	}
	ans += 1ll*cur*(cur-1)/2;

	cur = 1;
	REP(i, 1, n){
		if(A[i] == A[i-1]) cur++;
		else{
			ans -= 1ll*cur*(cur-1)/2;
			cur = 1;
		}
	}
	ans -= 1ll*cur*(cur-1)/2;

	std::cout << ans << "\n";

	return 0;
}