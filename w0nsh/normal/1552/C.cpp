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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		std::vector<bool> used(2*n);
		std::vector<PII> pr;
		FOR(i, k){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			used[a] = true;
			used[b] = true;
			pr.push_back(MP(a, b));
		}

		VI left;
		FOR(i, 2*n) if(!used[i]) left.push_back(i);
		FOR(j, SZ(left) / 2){
			pr.push_back(MP(left[j], left[SZ(left)/2 + j]));
		}

		int ans = 0;
		FOR(i, n){
			REP(j, i+1, n){
				std::vector<PII> elo;
				elo.push_back(MP(pr[i].X, 0));
				elo.push_back(MP(pr[i].Y, 0));
				elo.push_back(MP(pr[j].X, 1));
				elo.push_back(MP(pr[j].Y, 1));
				std::sort(elo.begin(), elo.end());
				bool bad = false;
				FOR(h, 3) if(elo[h].Y == elo[h+1].Y) bad = true;
				if(!bad) ans++;
			}
		}
		std::cout << ans << "\n";

	}

	return 0;
}