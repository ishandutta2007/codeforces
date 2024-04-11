#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353; // 2 * 2 * ... * 2 * 7 * 17
int R;

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e >>= 1;
	}
	return ret;
}

inline int DOD(int a, int b){
	return (a+b >= MOD ? a+b-MOD : a+b);
}
inline int ODJ(int a, int b){
	return (a-b < 0 ? a-b+MOD : a-b);
}
void transform(std::vector<int> &a, bool inv=false){
	int n = (int)a.size();
	int cnt = 0;
	for(int sz = 1; sz < n; sz *= 2){
		cnt++;
		for(int i = 0; i < n; i += sz*2){
			for(int j = i; j < i+sz; ++j){
				int u = a[j], v = a[j+sz];
				a[j] = DOD(u, v), a[j+sz] = ODJ(u, v);
			}
		}
	}
	if(inv){
		int mn = modpow(2, cnt);
		mn = modpow(mn, MOD-2);
		FOR(i, n) a[i] = (1ll*a[i]*mn)%MOD;
	}
}


VI topo;
std::vector<VI> g;
std::vector<bool> vis;
void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]) if(!vis[ch]) dfs(ch);
	topo.push_back(v);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	// VI siema(1<<18);
	// siema[0] = 1;
	// siema[2] = 0;
	// transform(siema);
	// FOR(i, 1<<18) siema[i] = (1ll*siema[i]*siema[i])%MOD;
	// transform(siema, true);
	// FOR(i, 4) std::cout << siema[i] << " ";
	// std::cout << std::endl;
	// return 0;

	int n, m;
	std::cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
	}
	FOR(i, n) if(!vis[i]) dfs(i);
	VI szparag(n);
	std::vector<int> nw(n, -1);
	TRAV(i, topo){
		TRAV(ch, g[i]) nw[szparag[ch]] = i;
		szparag[i] = 0;
		while(nw[szparag[i]] == i) szparag[i]++;
		assert(szparag[i] < n);
	}
	std::vector<int> cnt(n);
	FOR(i, n) cnt[szparag[i]]++;

	std::vector<int> poly(1<<18);
	int mn = modpow(n+1, MOD-2);
	FOR(i, n){
		poly[i] = (1ll*cnt[i]*mn)%MOD;
	}

	transform(poly);
	FOR(i, 1<<18){
		int dw = ODJ(1, poly[i]);
		poly[i] = (1ll*modpow(n+1, MOD-2)*modpow(dw, MOD-2))%MOD;
	}
	transform(poly, true);

	std::cout << ODJ(1, poly[0]) << "\n";

	return 0;
}