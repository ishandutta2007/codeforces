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
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n){
			std::cin >> A[i];
		}
		VI deg(n);
		FOR(i, n-1){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			deg[a]++;
			deg[b]++;
		}
		ll ans = 0;
		FOR(i, n) ans += A[i];
		std::vector<int> add;
		FOR(i, n){
			FOR(j, deg[i]-1) add.push_back(A[i]);
		}
		std::sort(add.begin(), add.end());
		std::reverse(add.begin(), add.end());
		std::cout << ans << " ";
		FOR(i, SZ(add)){
			ans += add[i];
			std::cout << ans << " ";
		}
		std::cout << "\n";
	}

	return 0;
}