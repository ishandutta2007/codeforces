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

void fail(){
	std::cout << "No\n";
	std::exit(0);
}

PII g[15][5005];

PII START;
int MASK;
bool GOOD;
std::vector<PR<PII, int> > rozw;
std::vector<std::vector<ll> > A;

void dfs(int a, int b){
	if(MASK & (1<<a)){
		if(MP(a, b) == START) GOOD = true;
	}else if(g[a][b].X != -1){
		MASK = MASK | (1<<a);
		rozw.push_back(MP(g[a][b], a));
		dfs(g[a][b].X, g[a][b].Y);
	}
}

int dp[1<<15];
std::vector<PR<PII, int> > can[1<<15];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int k;
	std::cin >> k;
	std::vector<ll> want(k);
	std::vector<ll> sum(k);
	
	A.resize(k);
	ll all = 0;
	FOR(i, k){
		int n;
		std::cin >> n;
		FOR(j, n){
			ll a;
			std::cin >> a;
			A[i].push_back(a);
			all += a;
			sum[i] += a;
		}
		std::sort(A[i].begin(), A[i].end());
	}
	if(all%k != 0) fail();
	FOR(i, k){
		want[i] = all/k - sum[i];
//		std::cerr << want[i] << " ";
	}
//	std::cerr << "\n";
	FOR(i, k) FOR(j, SZ(A[i])) g[i][j] = MP(-1, -1);
	FOR(i, k){
		FOR(j, SZ(A[i])){
			FOR(e, k){
				ll his = A[i][j]-want[e];
				if(i == e && his != A[i][j]) continue;
				auto it = std::lower_bound(A[e].begin(), A[e].end(), his);
				if(it != A[e].end() && *it == his){
					g[e][it-A[e].begin()] = MP(i, j);
//					std::cerr << "adding edge " << e << " " << (int)(it-A[e].begin()) << " , " << i << " " << j << "\n";
				}
			}
		}
	}
	FOR(i, k){
		FOR(j, SZ(A[i])){
			rozw.clear();
			MASK = 0;
			START = MP(i, j);
			GOOD = false;
			dfs(i, j);
			if(GOOD){
				can[MASK] = rozw;
			}
		}
	}

	FOR(i, 1<<k) dp[i] = -1;
	dp[0] = -2;

	REP(mask, 1, 1<<k){
		int sub = mask;
		while(sub > 0){
			if(dp[mask^sub] != -1 && SZ(can[sub])){
				dp[mask] = sub;
				break;
			}
			sub = (sub-1)&mask;
		}
	}

	if(dp[(1<<k)-1] == -1) fail();
	std::vector<PII> ans(k);
	int cur = (1<<k)-1;
	while(cur > 0){
		TRAV(x, can[dp[cur]]){
			ans[x.X.X] = MP(A[x.X.X][x.X.Y], x.Y);
		}
		cur = cur^dp[cur];
	}
	std::cout << "Yes\n";
	TRAV(i, ans) std::cout << i.X << " " << i.Y+1 << "\n";
	
	return 0;
}