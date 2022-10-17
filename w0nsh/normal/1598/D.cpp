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

ll we3(ll n){
	return (1ll * n * (n-1) * (n-2)) / 6;
}
ll we2(ll n){
	return (1ll * n * (n-1)) / 2;
}

void solve(){
	int n;
	std::cin >> n;
	std::map<PII, int> map;
	std::map<int, int> fs;
	std::map<int, int> sc;
	std::map<int, VI> kto;


	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		kto[a].push_back(b);
		map[MP(a, b)]++;
		fs[a]++;
		sc[b]++;
	}

	ll ans = 0;
	ll bad_fs = 0;
	ll bad_sc = 0;
	TRAV(x, fs) bad_fs += we2(x.Y);
	TRAV(x, sc) bad_sc += we2(x.Y);

	for(auto[pr, ile] : map){
		ans += we2(n-fs[pr.X]) - (bad_fs - we2(fs[pr.X]));
		ans += we2(n-sc[pr.Y]) - (bad_sc - we2(sc[pr.Y]));
	}
	assert(ans%3 == 0);
	ans /= 3;

	VI sum(2);
	std::vector<std::map<int, int>> cnt(2);
	ll matching = 0;

	auto add = [&](int co, int kt, int val){
		matching -= 1ll * cnt[kt][co] * (sum[kt^1] - cnt[kt^1][co]);
		cnt[kt][co] += val;
		sum[kt] += val;
		matching += 1ll * cnt[kt][co] * (sum[kt^1] - cnt[kt^1][co]);
	};

	TRAV(pr, map) add(pr.X.Y, 1, 1);
	for(auto[x, vec] : kto){
		TRAV(i, vec) add(i, 1, -1);

		TRAV(i, vec){
			ans -= matching - (1ll * cnt[0][i] * (sum[1] - cnt[1][i]) + 1ll * cnt[1][i] * (sum[0] - cnt[0][i]));
		}

		TRAV(i, vec) add(i, 0, 1);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}