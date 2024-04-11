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

int n, best;
VI A;
std::vector<VI> g, divs;

std::vector<PII> dfs(int v, int par){
	std::vector<PII> ret(SZ(divs[A[v]]));
	if(v != 0 && SZ(g[v]) == 1){
		FOR(i, SZ(divs[A[v]])){
			ret[i] = MP(1, 0);
			best = std::max(best, 1);
		}
		return ret;
	}
	TRAV(ch, g[v]){
		if(ch == par) continue;
		auto vec = dfs(ch, v);
		if(std::__gcd(A[ch], A[v]) == 1) continue;
		FOR(i, SZ(divs[A[v]])){
			if(A[ch] % divs[A[v]][i] != 0) continue;
			int place = std::distance(divs[A[ch]].begin(),
				std::lower_bound(divs[A[ch]].begin(), divs[A[ch]].end(), divs[A[v]][i]));
			if(vec[place].X > ret[i].X){
				ret[i].Y = ret[i].X;
				ret[i].X = vec[place].X;
			}else if(vec[place].X > ret[i].Y){
				ret[i].Y = vec[place].X;
			}
		}
	}
	FOR(i, SZ(divs[A[v]])){
		ret[i].X++;
		best = std::max(best, ret[i].X+ret[i].Y);
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	divs.resize(200005);
	g.resize(n);
	FOR(i, n) std::cin >> A[i];
	REP(i, 2, 200001){
		for(int j = i; j < 200001; j += i){
			divs[j].push_back(i);
		}
	}
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	std::cout << best;
	return 0;
}