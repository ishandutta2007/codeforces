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

constexpr int MOD = 998244353;

int brut(VI A){
	int n = SZ(A);
	int ans = 0;
	FOR(mask, 1<<n){
		VI C, P;
		FOR(i, n) if(mask & (1<<i)) C.push_back(i); else P.push_back(i);
		bool good = true;
		REP(i, 1, SZ(C)-1){
			if(C[i] - C[i-1] > C[i+1] - C[i]) good = false;
		}
		REP(i, 1, SZ(P)-1){
			if(P[i] - P[i-1] < P[i+1] - P[i]) good = false;
		}
		if(!good) continue;
		ll sum = 0;
		TRAV(i, C) sum -= A[i];
		TRAV(i, P) sum += A[i];
		if(sum > 0) ans++;
	}
	return ans;
}

int get(VI A, ll one, ll two){
	int n = SZ(A);
	ll sum = two - one;
	FOR(i, n) sum += A[i];

	ll ans = 0;
	if(sum > 0) ans++;

	std::multiset<PR<ll, int>> set;
	std::vector<ll> vals(n);
	for(int i = 1; i < n; i += 2){
		sum -= A[i] * 2;
		set.insert(MP(sum, i));
		vals[i] = sum;
	}

	while(SZ(set) && set.begin()->X <= 0) set.erase(set.begin());

	int iter = 1;
	ll add = 0;
	for(int i = 1; i < n; i += 2){
		add -= A[i-1]*2;
		while(SZ(set) && set.begin()->X+add <= 0) set.erase(set.begin()), ans += iter;
		iter++;
		auto it = set.find(MP(vals[i], i));
		if(it != set.end()){
			set.erase(it);
			ans += iter;
		}
	}
	assert(SZ(set) == 0);

	// std::cout << "init " << one << " vs " << two << std::endl;
	// FOR(i, n) std::cout << A[i] << " ";
	// std::cout << "\n = " << ans << std::endl;

	return ans%MOD;
}

int solve(VI A){
	int n = SZ(A);
	ll ans = 0;
	ll a1 = 0;
	ll a2 = 0;
	FOR(i, n) a2 += A[i];
	ans++;
	for(int i = n-1; i >= 0; --i){
		a2 -= A[i];
		a1 += A[i];
		if(a2 > a1) ans++;
	}

	FOR(fs, 2){
		FOR(sc, 2){
			ll one = 0, two = 0;
			VI nw;
			if(fs == 0){
				one += A[0];
			}else{
				two += A[0];
				one += A[1];
			}
			if(sc == 0){
				two += A[n-1];
			}else{
				one += A[n-1];
				two += A[n-2];
			}

			VI ar;
			REP(i, fs+1, n-sc-1) {
				ar.push_back(A[i]);
			}
			ans = (ans + get(ar, one, two))%MOD;
			if(SZ(ar) > 0){
				std::reverse(ar.begin(), ar.end());
				one += ar.back();
				ar.pop_back();
				std::reverse(ar.begin(), ar.end());
				ans = (ans + get(ar, one, two))%MOD;
			}
		}
	}

	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	// std::srand(1337);
	// auto los = [&](int a, int b){
	// 	return a + std::rand()%(b-a+1);
	// };
	// while(true){
	// 	int n = los(4, 15);
	// 	VI A(n);
	// 	FOR(i, n) A[i] = los(1, 1000000000);
	// 	std::cout << solve(A) << " vs " << brut(A) << std::endl;
	// 	if(solve(A) != brut(A)){
	// 		FOR(i, n) std::cout << A[i] << " ";
	// 		return 0;
	// 	}
	// }

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		std::cout << (n <= 3 ? brut(A) : solve(A)) << "\n";
	}

	return 0;
}