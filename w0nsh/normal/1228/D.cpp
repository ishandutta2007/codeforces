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

int n, m;
std::set<int> alive;
std::vector<VI> g;
VI ans;
VI repr;
int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	repr[a] = b;
}

void bfs(int v, int col){
	std::queue<int> que;
	que.push(v);
	while(SZ(que)){
		int cur = que.front();
		que.pop();
		ans[cur] = col;
		int last = 0;
		TRAV(nw, g[cur]){
			auto it = alive.upper_bound(last);
			while(it != alive.end() && *it < nw){
				Union(cur, *it);
				que.push(*it);
				it++;
				alive.erase(std::next(it, -1));
			}
			last = nw;
		}
		auto it = alive.upper_bound(last);
		while(it != alive.end()){
			Union(cur, *it);
			que.push(*it);
			it++;
			alive.erase(std::next(it, -1));
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	ans.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n) std::sort(g[i].begin(), g[i].end());
	repr.resize(n);
	FOR(i, n) repr[i] = i;
	FOR(i, n) alive.insert(i);
	int cnt = 0;
	FOR(i, n){
		if(alive.count(i)) bfs(i, cnt), cnt++;
	}
	if(cnt != 3){
		std::cout << -1;
		return 0;
	}
	FOR(i, n){
		TRAV(ch, g[i]){
			if(Find(i) == Find(ch)){
				std::cout << -1;
				return 0;
			}
		}
	}
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}