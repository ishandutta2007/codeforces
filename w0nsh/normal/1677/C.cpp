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
	int n;
	std::cin >> n;
	VI A(n), B(n);
	FOR(i, n) std::cin >> A[i], A[i]--;
	FOR(i, n) std::cin >> B[i], B[i]--;

	std::vector<VI> g(n);
	FOR(i, n){
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}

	std::vector<bool> vis(n);

	int cnt = 0;
	std::function<void(int)> dfs = [&](int v){
		vis[v] = true;
		cnt++;
		TRAV(ch, g[v]) if(!vis[ch]) dfs(ch);
	};

	std::array<std::vector<int>, 2> cyc{};
	FOR(i, n){
		if(!vis[i]){
			cnt = 0;
			dfs(i);
			cyc[cnt%2].push_back(cnt);
		}
	}

	int lo = 1;
	int hi = n;

	ll ans = 0;
	FOR(pr, 2){
		auto& vec = cyc[pr];
		std::sort(vec.begin(), vec.end());
		std::reverse(vec.begin(), vec.end());
		if(pr == 0){
			TRAV(len, vec){
				VI heh(len);
				FOR(i, len){
					if(i % 2 == 0) heh[i] = hi--;
					else heh[i] = lo++;
				}
				FOR(i, len){
					ans += std::abs(heh[i] - heh[(i+1)%len]);
				}
			}
		}else{
			TRAV(len, vec){
				VI heh(len);
				FOR(i, len){
					if(i == len-1) break;
					if(i % 2 == 0) heh[i] = hi--;
					else heh[i] = lo++;
				}
				FOR(i, len-2){
					ans += std::abs(heh[i] - heh[i+1]);
				}
				if(len > 1){
					ans += std::abs(heh[0] - heh[len - 2]);
				}
			}
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