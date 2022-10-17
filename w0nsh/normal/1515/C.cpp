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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, m, x;
		std::cin >> n >> m >> x;

		std::priority_queue<PII> que;
		FOR(i, m) que.push(MP(0, i));
		VI ans(n);
		FOR(i, n){
			int a;
			std::cin >> a;
			auto top = que.top();
			que.pop();
			ans[i] = top.Y;
			top.X -= a;
			que.push(top);
		}

		std::cout << "YES\n";
		FOR(i, n) std::cout << ans[i]+1 << " ";
		std::cout << "\n";

	}

	return 0;
}