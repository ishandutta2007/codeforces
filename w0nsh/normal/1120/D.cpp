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

int n;
VI C;
std::vector<VI> g;

constexpr ll INF = 1000000666ll*1000000666ll;
ll dp[200005][2];
ll bez[200005][2];

void dfs(int v, int par=-1){
	if(SZ(g[v]) == 1 && v != 0){
		dp[v][0] = C[v];
		dp[v][1] = 0;
		return;
	}

	ll sum = 0;
	TRAV(ch, g[v]) if(ch != par){
		dfs(ch, v);
		sum += dp[ch][0];
	}

	dp[v][0] = sum;
	dp[v][1] = INF;
	TRAV(ch, g[v]) if(ch != par){
		dp[v][0] = std::min(dp[v][0], sum - dp[ch][0] + dp[ch][1] + C[v]);
		dp[v][1] = std::min(dp[v][1], sum - dp[ch][0] + dp[ch][1]);
	}
}

void dfs2(int v, int par=-1){

	std::vector<ll> pref, suf;
	ll sum = 0;
	pref.push_back(INF);
	int ile = 0;
	TRAV(ch, g[v]) if(ch != par){
		pref.push_back(std::min(pref.back(), dp[ch][1] - dp[ch][0]));
		ile++;
		sum += dp[ch][0];
	}
	suf.push_back(INF);
	for(int xd = SZ(g[v])-1; xd >= 0; --xd){
		int ch = g[v][xd];
		if(ch == par) continue;
		suf.push_back(std::min(suf.back(), dp[ch][1] - dp[ch][0]));
	}

	int kto = 0;
	TRAV(ch, g[v]) if(ch != par){
		bez[ch][0] = bez[v][0] + sum - dp[ch][0];
		ll hehe = std::min(bez[v][0] + C[v], bez[v][1]);
		bez[ch][0] = std::min(bez[ch][0], hehe + sum - dp[ch][0] + std::min(pref[kto], suf[ile-kto-1]));

		bez[ch][1] = bez[v][0] + sum - dp[ch][0] + C[v];
		bez[ch][1] = std::min(bez[ch][1], bez[v][1] + sum - dp[ch][0]);

		dfs2(ch, v);
		kto++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	C.resize(n);
	FOR(i, n) std::cin >> C[i];
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	bez[0][0] = 0;
	bez[0][1] = INF;
	dfs2(0);

	ll cost = dp[0][0];

	VI ans;
	FOR(i, n){
		if(bez[i][0] + dp[i][1] + C[i] == cost){
			ans.push_back(i);
		}
	}

	std::cout << cost << " " << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i+1 << " ";

	return 0;
}