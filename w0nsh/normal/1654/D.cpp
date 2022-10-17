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

constexpr int MOD = 998244353;
constexpr int N = 200005;

std::vector<std::vector<PII>> fact;
std::vector<std::vector<PR<int, PII>>> g;

std::vector<int> ile;
std::vector<int> max;

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*a*ret)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

VI invs;

int sum;

int pdz(int a, int b){
	return (1ll * a * invs[b]) % MOD;
}

void dfs(int v, int co=1, int par=-1){
	sum = (sum + co) % MOD;

	// std::cout << "tera " << v << std::endl;

	for(auto[ch, pr] : g[v]){
		if(ch == par) continue;

		for(auto[i, cnt] : fact[pr.X]){
			ile[i] -= cnt;
		}
		for(auto[i, cnt] : fact[pr.Y]){
			ile[i] += cnt;
			if(ile[i] > max[i]){
				max[i] = ile[i];
			}
		}

		dfs(ch, (1ll * co * pdz(pr.X, pr.Y))%MOD, v);

		for(auto[i, cnt] : fact[pr.X]){
			ile[i] += cnt;
		}
		for(auto[i, cnt] : fact[pr.Y]){
			ile[i] -= cnt;
		}
	}
}

void solve(){
	int n;
	std::cin >> n;
	g = std::vector<std::vector<PR<int, PII>>>(n);
	ile = std::vector<int>(n+1);
	max = std::vector<int>(n+1);
	sum = 0;
	FOR(i, n-1){
		int a, b, x, y;
		std::cin >> a >> b >> x >> y;
		a--;b--;
		g[a].push_back(MP(b, MP(y, x)));
		g[b].push_back(MP(a, MP(x, y)));
	}

	dfs(0);

	REP(i, 2, n+1){
		// if(max[i] > 0){
			// std::cout << "mam " << i << " x " << max[i] << std::endl;
		// }
		FOR(j, max[i]){
			sum = (1ll * sum * i) % MOD;
		}
	}

	std::cout << sum << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	invs.resize(N);
	REP(i, 1, N) invs[i] = modpow(i, MOD-2);

	fact.resize(N);
	std::vector<bool> comp(N);
	for(int i = 2; i < N; ++i){
		if(!comp[i]){
			for(int j = i; j < N; j += i){
				int xd = j;
				int cnt = 0;
				while(xd % i == 0) {
					cnt++;
					xd /= i;
				}
				assert(cnt >= 1);
				fact[j].push_back(MP(i, cnt));
				comp[j] = true;
			}
		}
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}