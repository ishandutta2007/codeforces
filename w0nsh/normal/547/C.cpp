#pragma GCC optimize "O3"
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

	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	const int M = 500005;
	std::vector<VI> dziel(M);
	VI mob(M, 1);
	std::vector<bool> prime(M, true);
	for(int i = 2; i < M; ++i){
		if(prime[i]){
			for(int j = i; j < M; j += i){
				prime[j] = false;
				if(j%(1ll*i*i) == 0) mob[j] = 0;
				else mob[j] *= -1;
			}
		}
	}
	REP(i, 1, 10) std::cerr << mob[i] << " ";
	std::cerr << std::endl;

	REP(i, 1, M){
		for(int j = i; j < M; j += i){
			dziel[j].push_back(i);
		}
	}

	VI cnt(M);
	std::vector<bool> mam(n);

	ll ans = 0;

	auto ile = [&](int x){
		ll ret = 0;
		TRAV(d, dziel[x]) ret += mob[d]*cnt[d];
		return ret;
	};

	FOR(_, q){
		int x;
		std::cin >> x;
		x--;
		if(mam[x]){
			TRAV(d, dziel[A[x]]) cnt[d]--;
			ans -= ile(A[x]);
		}else{
			ans += ile(A[x]);
			TRAV(d, dziel[A[x]]) cnt[d]++;
		}
		std::cout << ans << "\n";
		mam[x] = !mam[x];
	}


	return 0;
}