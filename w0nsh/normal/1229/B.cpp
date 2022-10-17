#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int LOG = 18;

int n;
std::vector<VI> g;
std::vector<ll> A;
int lev[100005];
int par[LOG][100005];
ll gc[LOG][100005];

void dfs(int v, int parent=-1){
	par[0][v] = parent;
	if(parent != -1) gc[0][v] = std::gcd(A[v], A[parent]);
	else gc[0][v] = A[v];
	TRAV(ch, g[v]){
		if(ch != parent){
			lev[ch] = lev[v]+1;
			dfs(ch, v);
		}
	}
}

ll get(int v, int a){
	a--;
	ll gx = A[v];
	for(int i = LOG-1; i >= 0; --i){
		if((1<<i) <= a) gx = std::gcd(gx, gc[i][v]), v = par[i][v], a -= (1<<i);
	}
	return gx;
}
const int MOD = 1000000007;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lev[0] = 1;
	dfs(0);
	REP(i, 1, LOG){
		FOR(j, n){
			par[i][j] = (par[i-1][j] == -1 ? -1 : par[i-1][par[i-1][j]]);
			gc[i][j] = (par[i-1][j] == -1 ? gc[i-1][j] : std::gcd(gc[i-1][j], gc[i-1][par[i-1][j]]));
		}
	}
	int ans = 0;
	FOR(i, n){
		int pos = i;
		while(pos != -1){
			int v = pos;
			ll cur = get(i, lev[i]-lev[v]+1);
			for(int l = LOG-1; l >= 0; --l){
				if(lev[v]-(1<<l) > 0 && std::gcd(cur, gc[l][v]) == cur) v = par[l][v];
			}
			ans = (1ll*ans+1ll*cur*(lev[pos]-lev[v]+1))%MOD;
			pos = par[0][v];
		}
	}
	std::cout << ans << "\n";
	return 0;
}