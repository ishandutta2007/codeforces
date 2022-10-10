#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1 << 17;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int a[2][ms];
int b[2][ms];

void FWHT(int c[ms], int mod, bool inv = false) {
	for(int len = 1; len < ms; len += len) {
		for(int i = 0; i < ms; i += len + len) {
			for(int j = 0; j < len; j++) {
				int u = c[i+j], v = c[i+j+len];
				c[i+j] = (u+v) % mod;
				c[i+j+len] = (u-v+mod) % mod;
			}
		}
	}
	if(inv) {
		int two = (mod + 1) / 2;
		int rev = 1;
		for(int i = 0; i < 17; i++) {
			rev = (long long) rev * two % mod;
		}
		for(int i = 0; i < ms; i++) {
			c[i] = (long long) c[i] * rev % mod;
		}
	}
}

bool visit[ms];
int up[ms], cost[ms];
std::vector<std::pair<int, int>> edges[ms];
std::set<std::pair<int, int>> haha;

void dfs(int on, int par) {
	//std::cout << "visiting " << on << std::endl;
	//std::cout << "par is " << par << '\n';
	up[on] = par;
	visit[on] = true;
	for(auto e : edges[on]) {
		std::pair<int, int> hmm(std::min(e.first, on), std::max(e.first, on));
		if(haha.count(hmm)) continue;
		haha.insert(hmm);
		if(visit[e.first]) {
			//std::cout << "cycle in " << on << std::endl;
			//std::cout << e.first << std::endl;
			for(int i = 0; i < ms; i++) {
				b[0][i] = b[1][i] = 0;
			}
			b[0][e.second]++;
			b[1][e.second]++;
			int x = on;
			while(x != e.first) {
				b[0][cost[x]]++;
				b[1][cost[x]]++;
				x = up[x];
			}
			FWHT(b[0], MOD);
			FWHT(b[1], MOD2);
			for(int i = 0; i < ms; i++) {
				a[0][i] = (long long) a[0][i] * b[0][i] % MOD;
				a[1][i] = (long long) a[1][i] * b[1][i] % MOD2;
			}
			//std::cout << "cycle out" << std::endl;
		} else {
			cost[e.first] = e.second;
			dfs(e.first, on);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < ms; i++) {
		a[0][i] = a[1][i] = 1;
	}
	int n, m;
	std::cin >> n >> m;
	int tot = 0;
	while(m--) {
		int u, v, d;
		std::cin >> u >> v >> d;
		u--;v--;
		edges[u].emplace_back(v, d);
		edges[v].emplace_back(u, d);
		tot ^= d;
	}
	dfs(0, -1);
	FWHT(a[0], MOD, true);
	FWHT(a[1], MOD2, true);
	int ans = -1;
	for(int i = 0; i < ms; i++) {
		if(!a[0][i] && !a[1][i]) continue;
		if(ans == -1 || (ans ^ tot) > (i ^ tot)) {
			ans = i;
		}
	}
	std::cout << (tot^ans) << ' ' << a[0][ans] << '\n';
}