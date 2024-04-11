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
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		std::map<int, PII> map;
		FOR(i, n){
			int a, f;
			std::cin >> a >> f;
			map[a].X++;
			if(f) map[a].Y++;
		}
		std::vector<PII> have;
		TRAV(i, map) have.push_back(i.Y);
		std::sort(have.begin(), have.end());
		int ans = 0;
		int ans2 = 0;
		int cur = have.back().X;
		std::priority_queue<int> que;
		auto it = have.end();
		for(int i = n; i >= 1; --i){
			while(it != have.begin() && std::next(it, -1)->X >= i){
				it--;
				que.push(it->Y);
			}
			if(!que.empty()){
				int gt = que.top();
				que.pop();
				ans += i;
				ans2 += std::min(i, gt);
			}
		}
		std::cout << ans << " " << ans2 << "\n";
	}
	return 0;
}