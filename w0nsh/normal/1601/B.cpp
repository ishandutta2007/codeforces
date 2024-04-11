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

std::vector<VI> g;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	VI B(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];
	constexpr int INF = 1000000666;

	VI dist(n, INF);
	std::queue<int> que;
	que.push(n-1);
	dist[n-1] = 0;
	std::set<int> set;
	FOR(i, n-1) set.insert(i);
	VI from(n, -1);
	while(SZ(que)){
		int v = que.front();
		int orig = v;
		que.pop();

		v += B[v];
		assert(v < n);
		
		int left = v - A[v];
		assert(left >= -1);
		if(left == -1){
			VI ans;
			ans.push_back(-1);
			int ps = orig;
			while(ps != -1){
				ans.push_back(ps);
				ps = from[ps];
			}
			ans.pop_back();
			std::reverse(ans.begin(), ans.end());
			std::cout << SZ(ans) << "\n";
			TRAV(i, ans) std::cout << i+1 << " ";
			return 0;
		}

		auto it = set.lower_bound(left);
		while(it != set.end() && *it <= v){
			int ch = *it;
			auto nxt = std::next(it);
			set.erase(it);
			it = nxt;

			dist[ch] = dist[orig]+1;
			from[ch] = orig;
			que.push(ch);
		}
	}

	std::cout << -1 << "\n";

	return 0;
}