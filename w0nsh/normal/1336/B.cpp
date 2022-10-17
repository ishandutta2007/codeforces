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
	int t;
	std::cin >> t;
	while(t--){
		VI a(3);
		std::vector<VI> A(3);
		FOR(i, 3) std::cin >> a[i];
		FOR(i, 3){
			A[i].resize(a[i]);
			FOR(j, a[i]) std::cin >> A[i][j];
		}
		FOR(i, 3) std::sort(A[i].begin(), A[i].end());

		ll ans = 1000000000ll*1000000000ll*4ll;

		auto get = [&](int aa, int b, int c){
			return 1ll*(aa-b)*(aa-b) + 1ll*(aa-c)*(aa-c) + 1ll*(b-c)*(b-c);
		};

		auto post = [&](VI &vec, int v){
			auto it = std::lower_bound(vec.begin(), vec.end(), v);
			if(it == vec.end()) return -1;
			return *it;
		};

		auto prev = [&](VI &vec, int v){
			auto it = std::lower_bound(vec.begin(), vec.end(), v);
			if(it != vec.begin()){
				it--;
				return *it;
			}
			return -1;
		};

		auto solve = [&](){
			FOR(i, SZ(A[0])){
				int guy = A[0][i];
				int l1 = prev(A[1], guy);
				int r1 = post(A[1], guy);
				int l2 = prev(A[2], guy);
				int r2 = post(A[2], guy);
				if(l1 != -1){
					if(l2 != -1) ans = std::min(ans, get(l1, l2, guy));
					if(r2 != -1) ans = std::min(ans, get(l1, r2, guy));
				}
				if(r1 != -1){
					if(l2 != -1) ans = std::min(ans, get(r1, l2, guy));
					if(r2 != -1) ans = std::min(ans, get(r1, r2, guy));
				}
			}
		};

		solve();
		std::swap(A[0], A[1]);
		solve();
		std::swap(A[0], A[2]);
		solve();
		std::cout << ans << "\n";
	}

	return 0;
}