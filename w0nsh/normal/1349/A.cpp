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
	const int MX = 200005;
	std::vector<std::vector<PII> > fact(MX);
	std::vector<bool> prime(MX, true);
	for(int i = 2; i < MX; ++i){
		if(prime[i]){
			for(int j = i; j < MX; j += i){
				int cnt = 0;
				int cur = j;
				while(cur % i == 0){
					cur /= i;
					cnt++;
				}
				assert(cnt > 0);
				fact[j].push_back(MP(i, cnt));
				prime[j] = false;
			}
		}
	}

	int n;
	std::cin >> n;

	std::vector<VI> ile(MX);

	FOR(i, n){
		int a;
		std::cin >> a;
		TRAV(pr, fact[a]){
			ile[pr.X].push_back(pr.Y);
		}
	}


	ll ans = 1;
	REP(i, 2, MX){
		std::sort(ile[i].begin(), ile[i].end());
		assert(SZ(ile[i]) <= n);
		if(SZ(ile[i]) == n-1){
			FOR(j, ile[i][0]) ans *= i;
		}else if(SZ(ile[i]) == n){
			FOR(j, ile[i][1]) ans *= i;
		}
	}
	std::cout << ans;

	return 0;
}