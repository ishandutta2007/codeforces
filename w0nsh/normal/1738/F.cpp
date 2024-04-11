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

int ask(int v){
	std::cout << "? " << v+1 << std::endl;
	int x;
	std::cin >> x;
	return x-1;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<PII> D(n);
	FOR(i, n) std::cin >> D[i].X, D[i].Y = i;
	std::sort(D.begin(), D.end());
	std::reverse(D.begin(), D.end());

	std::vector<bool> vis(n);
	std::vector<VI> g(n);

	auto add_edge = [&](int a, int b){
		g[a].push_back(b);
		g[b].push_back(a);
	};

	FOR(i, n){
		auto[deg, v] = D[i];
		if(!vis[v]){
			vis[v] = true;
			FOR(j, deg){
				int kt = ask(v);
				add_edge(v, kt);
				if(vis[kt]) break;
				vis[kt] = true;
			}
		}
	}

	int CL = 1;
	std::fill(vis.begin(), vis.end(), false);
	VI col(n);
	std::function<void(int)> dfs = [&](int v){
		vis[v] = true;
		col[v] = CL;
		TRAV(ch, g[v]) if(!vis[ch]) dfs(ch);
	};
	FOR(i, n) if(!vis[i]){
		dfs(i);
		CL++;
	}

	std::cout << "!";
	FOR(i, n) std::cout << " " << col[i];
	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}