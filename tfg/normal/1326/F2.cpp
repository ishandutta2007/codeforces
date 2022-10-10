#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int N>
class PartitionSolver {
public:
	PartitionSolver() {
		std::vector<int> a;
		partitions.push_back(a);
		gen(1, N, a);
		std::sort(partitions.begin(), partitions.end());
		to.assign(partitions.size(), std::vector<int>(N+1, -1));
		for(int i = 0; i < (int) partitions.size(); i++) {
			int sum = 0;
			auto arr = partitions[i];
			for(auto x : arr) {
				sum += x;
			}
			for(int j = 1; j + sum <= N; j++) {
				arr = partitions[i];
				arr.push_back(j);
				std::sort(arr.begin(), arr.end());
				to[i][j] = getIndex(arr);
			}
		}
	}

	int size() const { return (int) partitions.size(); }
	int getIndex(const std::vector<int> &arr) const { return std::lower_bound(partitions.begin(), partitions.end(), arr) - partitions.begin(); }
	int add(int id, int num) const { return to[id][num]; }
	std::vector<int> getPermutation(int id) const { return partitions[id]; }
private:
	std::vector<std::vector<int>> partitions, to;
	void gen(int i, int sum, std::vector<int> &a) {
		if(i > sum) { return; }
		a.push_back(i);
		partitions.push_back(a);
		gen(i, sum - i, a);
		a.pop_back();
		gen(i+1, sum, a);
	}
};

const int me = 18;
const int ms = 1 << me;
 
bool mat[me][me];
int bits[ms];
long long dp[ms][me];
 
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) bits[i] = i % 2 + bits[i / 2];
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char ch;
			std::cin >> ch;
			mat[i][j] = ch == '1';
		}
	}
	PartitionSolver<18> solver;
	std::map<int, long long> memo;
	std::vector<std::vector<long long>> wtf(n+1, std::vector<long long>(1<<n, 0));
	{
		for(int j = 0; j < n; j++) {
			dp[1 << j][j] = 1;
		}
		for(int mask = 1; mask < (1<<n); mask++) {
			for(int j = 0; j < n; j++) {
				wtf[bits[mask]][mask] += dp[mask][j];
			}
			for(int k = 0; k < n; k++) {
				for(int j = 0; j < n; j++) {
					if((mask & (1 << j)) && !(mask & (1 << k)) && mat[j][k]) {
						dp[mask | (1 << k)][k] += dp[mask][j];
					}
				}
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int len = 1; len < (1<<n); len *= 2) {
				for(int i = 0; i < (1<<n); i += 2 * len) {
					for(int j = 0; j < len; j++) {
						wtf[k][i+j+len] += wtf[k][i+j];
					}
				}
			}
		}
		std::function<void(int, std::vector<long long>&)> go = [&](int i, std::vector<long long> &f) {
			for(int j = 1; j <= n; j++) {
				int nxt = solver.add(i, j);
				if(memo.count(nxt) || nxt == -1) continue;
				long long sum = 0;
				std::vector<long long> haha(1<<n);
				for(int mask = 0; mask < (1<<n); mask++) {
					haha[mask] = wtf[j][mask] * f[mask];
					sum += haha[mask] * ((bits[mask] % 2 == bits[(1<<n)-1] % 2) ? 1 : -1);
				}
				memo[nxt] = sum;
				go(nxt, haha);
			}
		};
		auto haha = std::vector<long long>(1<<n, 1);
		go(0, haha);
	}
	std::vector<long long> ans(1 << (n-1), 0);
	for(int i = 0; i < (1<<n)/2; i++) {
		int par = 0;
		int sum = 1;
		for(int j = 0; j < n-1; j++) {
			if((i >> j) & 1) {
				sum++;
			} else {
				par = solver.add(par, sum);
				sum = 1;
			}
		}
		par = solver.add(par, sum);
		assert(memo.count(par));
		ans[i] = memo[par];
	}
	for(int len = 1; len < (1<<n)/2; len *= 2) {
		for(int i = 0; i < (1<<n)/2; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				ans[i+j] -= ans[i+j+len];
			}
		}
	}
	for(int i = 0; i < (1<<n)/2; i++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << std::endl;
}