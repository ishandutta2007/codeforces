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

constexpr ll MOD = 1000000007;

ll modpow(ll a, ll e){
	ll ret = 1;
	while(e){
		if(e&1) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		e>>=1;
	}
	return ret;
}

bool bad[6][6];

std::map<std::string, int> map{
	{"green", 0},
	{"red", 1},
	{"blue", 2},
	{"orange", 3},
	{"white", 4},
	{"yellow", 5}
};

VI moz(int a, int b){
	VI ret;
	FOR(i, 6) if(!bad[a][i] && !bad[b][i]) ret.push_back(i);
	return ret;
}

typedef std::array<int, 6> AR;

AR merge(AR par, AR left, AR right){
	FOR(c, 6){
		if(par[c] == 0) continue;
		par[c] = 0;
		FOR(a, 6){
			FOR(b, 6){
				if(!bad[a][c] && !bad[b][c]){
					par[c] = (par[c] + 1ll * left[a] * right[b]) % MOD;
				}
			}
		}
	}
	return par;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	FOR(i, 6) bad[i][i] = true;
	bad[0][2] = bad[2][0] = true;
	bad[1][3] = bad[3][1] = true;
	bad[4][5] = bad[5][4] = true;

	int k;
	std::cin >> k;

	VI F(60);

	ll x = 6;
	F[0] = 1;
	FOR(i, k-1){
		ll y = (x * x) % MOD;

		ll xd = (y * modpow(3, MOD-2)) % MOD;
		x = (xd * 8) % MOD;
		F[i+1] = (x * modpow(6, MOD-2))%MOD;
	}

	--k;

	std::map<ll, int> must;
	int n;
	std::cin >> n;
	FOR(i, n){
		ll v;
		std::string s;
		std::cin >> v >> s;
		assert(map.count(s));
		must[v] = map[s];
	}

	std::map<ll, AR> dp;
	{
		ll min = (1ll<<k);
		ll max = (1ll<<(k+1))-1;
		for(auto[v, co] : must){
			if(v < min || v > max) continue;
			
			dp[v] = AR{};
			dp[v][co] = F[0];
		}
	}

	for(int lev = k-1; lev >= 0; --lev){
		ll min = (1ll<<lev);
		ll max = (1ll<<(lev+1))-1;

		std::map<ll, AR> next;

		AR heh;
		int f = F[k-1-lev];
		FOR(i, 6) heh[i] = f;
		AR ones;
		FOR(i, 6) ones[i] = 1;


		std::vector<ll> inter;
		if(min == max) inter.push_back(1);

		for(auto [v, co] : must){
			if(v < min || v > max) continue;
			inter.push_back(v);
		}
		for(auto pr : dp){
			inter.push_back(pr.X/2);
		}
		std::sort(inter.begin(), inter.end());
		inter.resize(std::unique(inter.begin(), inter.end()) - inter.begin());

		TRAV(v, inter){
			AR left = (dp.count(v*2) ? dp[v*2] : heh);
			AR right = (dp.count(v*2+1) ? dp[v*2+1] : heh);

			AR my = ones;
			if(must.count(v)){
				FOR(i, 6) if(i != must[v]) my[i] = 0;
			}

			next[v] = merge(my, left, right);
		}

		dp = next;
	}

	int sum = 0;
	FOR(i, 6) sum = (sum + dp[1][i])%MOD;
	std::cout << sum << "\n";

	return 0;
}