#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
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

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		std::map<int, VI> map;
		FOR(i, n){
			std::cin >> A[i];
			map[A[i]].push_back(i);
		}
		VI ans(n+1, -1);
		TRAV(pr, map){
			int last = -1;
			pr.Y.push_back(n);
			int mx = 0;
			TRAV(i, pr.Y){
				mx = std::max(mx, i-last);
				last = i;
			}
			if(ans[mx] == -1) ans[mx] = pr.X;
		}
		REP(i, 1, n+1){
			if(ans[i] == -1) ans[i] = ans[i-1];
			if(ans[i-1] != -1 && ans[i] != -1)
				ans[i] = std::min(ans[i], ans[i-1]);
		}
		FOR(i, n) std::cout << ans[i+1] << " ";
		std::cout << "\n";
		
	}

	return 0;
}