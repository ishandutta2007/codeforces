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

int n, m;
std::vector<VI> gr;
VI par;
std::vector<bool> vis;
VI lev;

void dfsgr(int v){
	vis[v] = true;
	TRAV(ch, gr[v]){
		if(vis[ch]) continue;
		lev[ch] = lev[v] + 1;
		par[ch] = v;
		dfsgr(ch);
	}
}

int lca(int a, int b){
	if(lev[a] > lev[b]) std::swap(a, b);
	while(lev[b] != lev[a]) b = par[b];
	while(a != b){
		a = par[a];
		b = par[b];
	}
	return a;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	gr.resize(n);
	vis.resize(n);
	par.resize(n, -1);
	lev.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfsgr(0);

	int q;
	std::cin >> q;
	VI dd(n);

	std::vector<VI> paths;

	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		int lc = lca(a, b);
		int pos = a;
		VI pth;
		while(pos != lc){
			dd[pos] ^= 1;
			pth.push_back(pos);
			pos = par[pos];
		}
		pth.push_back(lc);

		VI nd;
		pos = b;
		while(pos != lc){
			dd[pos] ^= 1;
			nd.push_back(pos);
			pos = par[pos];
		}
		while(SZ(nd)) pth.push_back(nd.back()), nd.pop_back();

		paths.push_back(std::move(pth));
	}

	bool good = true;
	FOR(i, n){
		if(dd[i]) good = false;
	}
	
	if(good){
		std::cout << "YES\n";
		TRAV(p, paths){
			std::cout << SZ(p) << "\n";
			TRAV(i, p) std::cout << i+1 << " ";
			std::cout << "\n";
		}
	}else{
		std::cout << "NO\n";

		std::vector<VI> ed(n);
		FOR(i, n) if(dd[i]){
			ed[i].push_back(par[i]);
			ed[par[i]].push_back(i);
		}

		std::fill(vis.begin(), vis.end(), false);
		int xd = 0;
		std::function<int(int)> dfs = [&](int v){
			vis[v] = true;
			int mam = 0;
			TRAV(ch, ed[v]) if(!vis[ch]){
				dfs(ch);
				mam++;
			}
			xd += mam / 2;
			return mam % 2;
		};

		int ans = 0;
		FOR(i, n) if(!vis[i]){
			xd = 0;
			if(dfs(i)) xd++;
			ans += xd;
		}

		std::cout << ans << "\n";
	}

	return 0;
}