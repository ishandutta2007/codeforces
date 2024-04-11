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
int m;
int modpow(int a, ll e){
	int ret = 1;
	while(e > 0){
		if(e&1ll) ret = (1ll*ret*a)%m;
		a = (1ll*a*a)%m;
		e>>=1;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	VI A;
	int n;
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	if(n > m+5) std::cout << 0;
	else{
	int	ans = 1;
		FOR(i, n){
			REP(j, i+1, n){
				ans = (1ll*ans*(std::abs(A[i]-A[j])))%m;
				if(ans < 0) ans += m;
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}