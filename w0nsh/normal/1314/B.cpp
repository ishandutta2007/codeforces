#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
const ll INF = 1000000000ll*1000000000ll;

ll dp[1<<19][4];
bool have[1<<17];
int BOTTOM;
void dfs(int v){
//	std::cout << "dfs " << v << std::endl;
	if(v >= BOTTOM) return;
	dfs(v<<1); dfs((v<<1)+1);

	FOR(i, 4) FOR(j, 4) FOR(s1, 2) FOR(s2, 2){
		ll mam = dp[v<<1][i]+dp[(v<<1)+1][j] + __builtin_popcount(i) + __builtin_popcount(j);
		int a = i;
		int b = j;
		if(s1 && (a&1)) a = 2;
		if(s2 && (b&1)) b = 2;
		if(a&2) mam++;
		if(b&2) mam++;
		dp[v][a|b] = std::max(dp[v][a|b], mam);
	}
//	std::cout << v << ": ";
//	FOR(i, 4) std::cout << dp[v][i] << " ";
//	std::cout << "\n";

/*
	dp[v][0] = std::max(dp[v][0], dp[v<<1][0]+dp[(v<<1)+1][0]);
	dp[v][1] = std::max(dp[v][1], std::max(dp[v<<1][1]+dp[(v<<1)+1][0],
										   dp[(v<<1)+1][1]+dp[v<<1][0])+1);
	FOR(i, 4) FOR(j, 4) if((i|j) & 2){
		int xd = 0;
		if(i&2) xd += 2;
		if(j&2) xd += 2;
		dp[v][2] = std::max(dp[v][2], dp[v<<1][i]+dp[(v<<1)+1][j]+xd);
	}
	dp[v][2] = std::max(dp[v][2], dp[v<<1][1]+2+)
	dp[v][3] = std::max(dp[v][3], dp[v<<1][3]+dp[(v<<1)+1][3]+6);
	*/
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 1<<19) FOR(j, 4) dp[i][j] = -INF;
	int n, k;
	std::cin >> n >> k;
	FOR(i, k){
		int a;
		std::cin >> a;
		have[a-1] = true;
	}
	BOTTOM = (1<<(n-2));
	FOR(i, BOTTOM){
		dp[BOTTOM+i][0] = 0;
		int moj = (have[4*i] || have[4*i+1]);
		moj += (have[4*i+2] || have[4*i+3]);
		if(have[4*i] || have[4*i+1] || have[4*i+2] || have[4*i+3]) 
			dp[BOTTOM+i][1] = dp[BOTTOM+i][2] = moj;
		if(have[4*i] + have[4*i+1] + have[4*i+2] + have[4*i+3] > 1)
			dp[BOTTOM+i][3] = moj;
	}
	dfs(1);
//	FOR(i, 4) std::cout << dp[1][i] << " ";
	ll ans = 0;
	ans = std::max(ans, dp[1][1]+3);
	ans = std::max(ans, dp[1][2]+3);
	ans = std::max(ans, dp[1][3]+4);
	std::cout << ans;
	return 0;
}