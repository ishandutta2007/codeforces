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

int dist(PII a, PII b){
	return std::abs(a.X-b.X) + std::abs(a.Y-b.Y);
}

bool check(PII a, PII b, PII c){
	return (dist(a, b) + dist(b, c) == dist(a, c)) ||
		(dist(a, c) + dist(c, b) == dist(a, b)) ||
		(dist(b, a) + dist(a, c) == dist(c, b));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];

		int ans = 0;
		FOR(s, n){
			REP(e, s, std::min(n, s+10)){
				bool good = true;
				REP(i, s, e+1){
					REP(j, i+1, e+1){
						REP(k, j+1, e+1){
							if(check(MP(A[i], i), MP(A[j], j), MP(A[k], k))){
								good = false;
								break;
							}
						}
						if(!good) break;
					}
					if(!good) break;
				}
				if(good) ans++;
			}
		}

		std::cout << ans << "\n";
	}

	return 0;
}