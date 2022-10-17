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

int n;
VI A;
std::vector<ll> sum;
std::vector<VI> g;

ll cur = 0;
ll max = 0;

void dfs0(int v, int par){
	sum[v] = A[v];
	TRAV(ch, g[v]){
		if(ch == par) continue;
		dfs0(ch, v);
		sum[v] += sum[ch];
	}
}

void dfs1(int v, int par, int dist){
	cur += 1ll*dist*A[v];
	TRAV(ch, g[v]){
		if(ch == par) continue;
		dfs1(ch, v, dist+1);
	}
}

void dfs2(int v, int par, ll nw){
	max = std::max(max, nw);
	TRAV(ch, g[v]){
		if(ch == par) continue;
		ll c = nw;
		c += sum[0];
		c -= 2ll*sum[ch];
		dfs2(ch, v, c);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	g.resize(n);
	sum.resize(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs0(0, -1);
	dfs1(0, -1, 0);
	dfs2(0, -1, cur);
	std::cout << max;
	return 0;
}