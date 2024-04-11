#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010000;
const long long INF = (long long) 1e18 + 10;

int size[ms];
int c = 1;
int to[ms][26];
long long k;
std::string txt;

void addString(std::string str) {
	int on = 0;
	for(auto ch : str) {
		int x = ch - 'a';
		if(to[on][x] == 0) to[on][x] = c++;
		on = to[on][x];
	}
}

void dfs(int on) {
	for(int i = 0; i < 26; i++) {
		if(to[on][i]) {
			dfs(to[on][i]);
			size[on] += size[to[on][i]];
		}
	}
	if(on) {
		size[on]++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m >> k;
	std::cin >> txt;
	for(int i = 0; i < n; i++) {
		addString(txt.substr(i, n-i));
	}
	dfs(0);
	int l = 1, r = size[0];
	std::string str;
	auto solve = [&](int pos) {
		//std::cout << "pos is " << pos << std::endl;
		str.clear();
		for(int on = 0; 1; ) {
			if(on) {
				pos--;
			}
			if(pos == 0) {
				break;
			}
			for(int i = 0; i < 26; i++) {
				if(to[on][i]) {
					if(size[to[on][i]] >= pos) {
						on = to[on][i];
						str += char(i + 'a');
						break;
					} else {
						pos -= size[to[on][i]];
					}
				}
			}
		}
		std::vector<int> trans(n, -1);
		for(int i = 0; i < n; i++) {
			int j = 0;
			while(i + j < n && j < (int) str.size() && str[j] == txt[i + j]) j++;
			if(i + j < n && j < (int) str.size()) {
				if(txt[i+j] < str[j]) {
					trans[i] = -1;
				} else {
					trans[i] = i + j + 1;
				}
			} else if(j == (int) str.size()) {
				trans[i] = i + j;
			} else {
				trans[i] = -1;
			}
			//std::cout << "at " << i << " trans is " << trans[i] << std::endl;
		}
		std::vector<long long> dp(n + 2, 0);
		dp[0] = 1;
		for(int rep = 0; rep < m; rep++) {
			std::vector<long long> nxt(n + 1, 0);
			for(int i = 0; i < n; i++) {
				if(trans[i] == -1) {
				} else {
					nxt[trans[i]] = std::min(k + 1, nxt[trans[i]] + dp[i]);
				}
			}
			for(int i = 1; i <= n; i++) {
				nxt[i] = nxt[i] + nxt[i-1];
				nxt[i] = std::min(nxt[i], k + 1);
				dp[i] = nxt[i];
			}
			dp[0] = 0;
			for(int i = 0; i <= n; i++) {
				//std::cout << dp[i] << (i == n ? '\n' : ' ');
			}
		}
		dp.pop_back();
		//std::cout << "with string " << str << " got " << dp.back() << '\n';
		return dp.back() >= k;
	};
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(solve(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	solve(l);
	std::cout << str << std::endl;
}