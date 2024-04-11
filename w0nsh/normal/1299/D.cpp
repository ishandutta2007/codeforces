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
typedef unsigned U;

const int MOD = 1000000007;
int n, m;
std::vector<std::vector<PII> > g;
std::vector<U> subs;
std::unordered_map<U, int> map;
int sum[374][374];
bool lz[374][374];

inline bool przec(U a, U b){
	return (a&b) != 1;
}

U add(U a, U b){
	U ret = 0;
	FOR(i, 32) if(a&(1u<<i)){
		FOR(j, 32) if(b&(1u<<j)){
			ret |= (1u<<(i^j));
		}
	}
	return ret;
}

U random(std::vector<U> &vec){
	return vec[std::rand()%SZ(vec)];
}

void prepare(){
	FOR(i, 32) subs.push_back(1|(1u<<i));
	FOR(i, 400000){
		U nw = add(random(subs), random(subs));
		if(std::find(subs.begin(), subs.end(), nw) == subs.end())
			subs.push_back(nw);
	}
	std::sort(subs.begin(), subs.end());
	assert(SZ(subs) == 374);
	FOR(i, 374) map[subs[i]] = i;
	FOR(i, 374) FOR(j, 374) sum[i][j] = map[add(subs[i], subs[j])],
							lz[i][j] = przec(subs[i], subs[j]);
}

int dp[100000][374];
std::vector<bool> one;
int subspace;
bool bad;
VI vis;
int tick;
VI pref;
VI pare;
VI wyn;
VI pre;
int asd;
void dfs(int v, int par){
	vis[v] = tick;
	pre[v] = asd++;
	TRAV(ch, g[v]) if(ch.X != par && !(one[ch.X] && vis[ch.X] != tick) && ch.X != 0){
		if(vis[ch.X]){
			if(pre[ch.X] < pre[v]){
				int xr = pref[ch.X]^pref[v]^ch.Y;
				if(xr == 0) bad = true;
				int other = map[1|(1u<<xr)];
				if(lz[subspace][other]) bad = true;
				subspace = sum[subspace][other];
			}
		}else{
			pref[ch.X] = pref[v] ^ ch.Y;
			pare[ch.X] = ch.Y;
			dfs(ch.X, v);
		}
	}
}

void przejdz(int i, int val){
	FOR(j, 374){
		if(!lz[j][val]){
			dp[i][sum[j][val]] = (dp[i][sum[j][val]]+dp[i-1][j]);
			if(dp[i][sum[j][val]] >= MOD) dp[i][sum[j][val]] -= MOD;
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
	}
	prepare();
	one.resize(n);
	pre.resize(n);
	vis.resize(n);
	pref.resize(n);
	pare.resize(n);
	TRAV(ch, g[0]) one[ch.X] = 1, pare[ch.X] = ch.Y;
	tick = 1;
	wyn.resize(n, -1);
	TRAV(ch, g[0]){
		tick++;
		subspace = map[1];
		bad = false;
		dfs(ch.X, 0);
		if(!bad) wyn[ch.X] = subspace;
	}
//	FOR(s, n) if(wyn[s] != -1){
//		std::cout << std::bitset<32>(subs[wyn[s]]) << std::endl;
//	}else{
//		std::cout << -1 << std::endl;
//	}
	std::vector<PR<PII, PII> > A;
	A.push_back(MP(MP(-1, -1), MP(-1, -1)));
	FOR(i, n) if(one[i]){
		bool was = false;
		TRAV(ch, g[i]) if(one[ch.X]){
			int lol = ch.Y^pare[ch.X]^pare[i];
			A.emplace_back();
			if(wyn[i] == -1 || wyn[ch.X] == -1){
				A.back() = MP(MP(0, -1), MP(-1, -1));
			}else{
				A.back().X.X = 0;
				A.back().X.Y = sum[wyn[i]][wyn[ch.X]];
				if(lz[wyn[i]][wyn[ch.X]]) A.back().X.Y = -1;
				A.back().Y.X = sum[wyn[i]][wyn[ch.X]];
				if(lz[wyn[i]][wyn[ch.X]]) A.back().Y.X = -1;
				A.back().Y.Y = -1;
				if(A.back().Y.X != -1 && lol != 0){
					A.back().Y.Y = sum[A.back().Y.X][map[1u|(1u<<lol)]];
					if(lz[A.back().Y.X][map[1|(1u<<lol)]]) A.back().Y.Y = -1;
				}
			}
			was = true;
			one[ch.X] = false;
		}
		if(!was) A.push_back(MP(MP(0, wyn[i]), MP(-1, -1)));
	}
	dp[0][0] = 1;
	REP(i, 1, SZ(A)){
		//std::cout << A[i].X.X << " " << A[i].X.Y << " " << A[i].Y.X << " " << A[i].Y.Y << std::endl;
		if(A[i].X.X != -1) przejdz(i, A[i].X.X);
		if(A[i].X.Y != -1) przejdz(i, A[i].X.Y);
		if(A[i].Y.X != -1) przejdz(i, A[i].Y.X);
		if(A[i].Y.Y != -1) przejdz(i, A[i].Y.Y);
	}
	int ans = 0;
	FOR(i, 374) ans = (1ll*ans+dp[SZ(A)-1][i])%MOD;
	std::cout << ans << "\n";
	return 0;
}