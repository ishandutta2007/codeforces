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

std::vector<VI> g;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	g.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n) std::sort(g[i].begin(), g[i].end());
	std::set<int> want;
	FOR(i, n) want.insert(i);
	int ans = -1;
	FOR(i, n) if(want.count(i)){
		ans++;
		std::queue<int> que;
		que.push(i);
		want.erase(i);
		while(SZ(que)){
			int v = que.front();
			que.pop();
			auto it = want.begin();
			while(it != want.end()){
				if(std::binary_search(g[v].begin(), g[v].end(), *it)){
					it++;
					continue;
				}
				que.push(*it);
				auto next = std::next(it);
				want.erase(it);
				it = next;
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}