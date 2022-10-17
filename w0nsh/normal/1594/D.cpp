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

void solve(){
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<PII>> g(n);

	FOR(i, m){
		int a, b;
		std::string s;
		std::cin >> a >> b >> s;
		a--;b--;
		g[a].push_back(MP(b, (int)(s[0] == 'i')));
		g[b].push_back(MP(a, (int)(s[0] == 'i')));
	}

	int cnt[2];
	int ans = 0;
	bool bad = false;
	VI col(n, -1);

	std::function<void(int)> dfs = [&](int v){
		cnt[col[v]]++;
		TRAV(ch, g[v]){
			if(col[ch.X] == -1){
				col[ch.X] = col[v] ^ ch.Y;
				dfs(ch.X);
				if(bad) break;
			}else{
				if(col[ch.X] != (col[v] ^ ch.Y)){
					bad = true;
					break;
				}
			}
		}
	};

	FOR(i, n) if(col[i] == -1){
		cnt[0] = cnt[1] = 0;
		col[i] = 0;
		dfs(i);
		ans += std::max(cnt[0], cnt[1]);
		if(bad){
			ans = -1;
			break;
		}
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