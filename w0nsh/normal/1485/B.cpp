#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q, k;
	std::cin >> n >> q >> k;
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];
	VI heh(n+1);
	REP(i, 2, n) heh[i] = A[i+1]-A[i-1]-2;
	std::vector<ll> pref(n+1);
	REP(i, 1, n+1){
		pref[i] = pref[i-1] + heh[i];
	}
	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		if(a == b){
			std::cout << k-1 << "\n";
		}else{
			ll sum = pref[b-1] - pref[a];
			sum += A[a+1]-2;
			sum += k-A[b-1]-1;
			std::cout << sum << "\n";
		}
	}

	return 0;
}