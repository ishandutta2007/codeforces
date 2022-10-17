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

std::vector<std::vector<PII> > g;
int n, k;

PR<ll, ll> dfs(int v, int par=-1){
	std::vector<PR<ll, int> > vec;
	std::vector<PR<ll, ll> > chil;
	int ind = 0;
	TRAV(ch, g[v]) if(ch.X != par){
		auto xd = dfs(ch.X, v);
		xd.X += ch.Y;
		std::swap(xd.X, xd.Y);
		chil.push_back(xd);
		vec.push_back(MP(xd.Y-xd.X, ind));
		ind++;
	}
	std::sort(vec.begin(), vec.end(), std::greater<PR<ll, int> >());
	PR<ll, ll> ret = MP(0ll, 0ll);
	int pos = 0;
	while(pos < k-1 && pos < SZ(vec)){
		int kto = vec[pos].Y;
		ret.X += std::max(chil[kto].X, chil[kto].Y);
		ret.Y += std::max(chil[kto].X, chil[kto].Y);
		pos++;
	}
	if(pos < SZ(vec)) ret.Y += std::max(chil[vec[pos].Y].X, chil[vec[pos].Y].Y), ret.X += chil[vec[pos].Y].X, pos++;
	while(pos < SZ(vec)) ret.X += chil[vec[pos].Y].X, ret.Y += chil[vec[pos].Y].X, pos++;
	ret.Y = std::max(ret.X, ret.Y);
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		std::cin >> n >> k;
		g = std::vector<std::vector<PII> >(n);
		FOR(i, n-1){
			int a, b, c;
			std::cin >> a >> b >> c;
			a--;b--;
			g[a].push_back(MP(b, c));
			g[b].push_back(MP(a, c));
		}
		auto xd = dfs(0);
		std::cout << std::max(xd.X, xd.Y) << "\n";
	}
	return 0;
}