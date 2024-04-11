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
	std::vector<VI> g(n);
	REP(i, 1, n){
		int p;
		std::cin >> p;
		p--;
		g[p].push_back(i);
	}
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;

	int ans = 0;

	std::function<int(int)> dfs = [&](int v){
		ll sum = 0;
		TRAV(ch, g[v]){
			sum += dfs(ch);
		}
		if(sum < A[v].X){
			ans++;
			sum = A[v].Y;
		}
		if(sum > A[v].Y) sum = A[v].Y;
		return sum;
	};
	dfs(0);

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >>t;
	while(t--) solve();

	return 0;
}