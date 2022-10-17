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

ll jazda(const VI& A){
	ll ret = 0;
	ll lw = 0;
	ll pr = SZ(A)-1;
	TRAV(i, A){
		ret += (lw - pr) * i;

		lw++;
		pr--;
	}

	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<VI> A(n, VI(m));
	std::vector<VI> B(m, VI(n));

	std::map<int, VI> mapx;
	std::map<int, VI> mapy;

	FOR(i, n){
		FOR(j, m){
			int a;
			std::cin >> a;
			mapx[a].push_back(i);
			mapy[a].push_back(j);
		}
	}

	ll ans = 0;
	TRAV(pr, mapx){
		std::sort(pr.Y.begin(), pr.Y.end());
		ans += jazda(pr.Y);
	}
	TRAV(pr, mapy){
		std::sort(pr.Y.begin(), pr.Y.end());
		ans += jazda(pr.Y);
	}

	std::cout << ans << "\n";

	return 0;
}