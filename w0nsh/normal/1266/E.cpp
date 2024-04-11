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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];
	VI have(n+1);
	int q;
	std::cin >> q;
	std::map<PII, int> map;
	ll ans = 0;
	FOR(i, n) ans += A[i+1];
	while(q--){
		int s, t, u;
		std::cin >> s >> t >> u;
		if(map[MP(s, t)] != 0){
			int h = map[MP(s, t)];
			if(have[h] <= A[h]){
				ans++;
			}
			have[h]--;
			map[MP(s, t)] = 0;
		}
		if(u != 0){
			if(have[u] < A[u]){
				ans--;
			}
			have[u]++;
			map[MP(s, t)] = u;
		}
		std::cout << ans << "\n";
	}
	return 0;
}