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

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	int ans = std::max(0, n-2);

	typedef long double K;
	FOR(fs, n){
		REP(sc, fs+1, n){
			K dif = static_cast<K>(A[sc] - A[fs]) / (sc - fs);
			K start = A[fs] - fs * dif;
			int bd = 0;
			FOR(i, n){
				if(std::abs(A[i] - (start + i * dif)) > 1e-8){
					bd++;
				}
			}
			ans = std::min(ans, bd);
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	return 0;
}