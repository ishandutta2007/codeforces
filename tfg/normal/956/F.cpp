#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mb = 163;

struct State {
	std::bitset<mb> a;
	int wtf = 0;

	State() {
		a[0] = true;
		wtf = 0;
	}

	void add(int x) {
		a |= a << x;
		wtf += x;
	}

	bool operator < (const State &o) const {
		if(wtf != o.wtf) {
			return wtf < o.wtf;
		}
		for(int i = 0; i < mb; i++) {
			if(a[i] != o.a[i]) return a[i] < o.a[i];
		}
		return false;
	}

	bool operator == (const State &o) const {
		for(int i = 0; i < mb; i++) {
			if(a[i] != o.a[i]) return false;
		}
		return true;
	}

	void print() {
		for(int i = 0; i < mb; i++) if(a[i]) std::cout << i << ' ';
		std::cout << '\n';
	}

	int best() const {
		int ans = mb;
		int sum = mb-1;
		while(!a[sum]) sum--;
		for(int i = 0; i <= sum; i++) {
			if(a[i]) {
				ans = std::min(ans, abs(i-(sum-i)));
			}
		}
		return ans;
	}
};

template<const int N>
class PartitionSolver {
public:
	PartitionSolver() {
		State a;
		partitions.push_back(a);
		//a.add(1);
		//partitions.push_back(a);
		for(int rep = 0; rep < N; rep++) {
			int sz = (int) partitions.size();
			for(int j = 0; j < sz; j++) {
				for(int ch = 1; ch <= 9; ch++) {
					a = partitions[j];
					a.add(ch);
					partitions.push_back(a);
				}
			}
			std::sort(partitions.begin(), partitions.end());
			partitions.resize(std::unique(partitions.begin(), partitions.end()) - partitions.begin());
		}
		//std::sort(partitions.begin(), partitions.end());
		to.assign(partitions.size(), std::vector<int>(10, -1));
		for(int i = 0; i < (int) partitions.size(); i++) {
			to[i][0] = i;
			for(int j = 1; j <= 9; j++) {
				auto arr = partitions[i];
				arr.add(j);
				to[i][j] = getIndex(arr);
			}
		}
	}

	int size() const { return (int) partitions.size(); }
	int getIndex(const State &arr) const { return std::lower_bound(partitions.begin(), partitions.end(), arr) - partitions.begin(); }
	int add(int id, int num) const { return to[id][num]; }
	State getPermutation(int id) const { return partitions[id]; }
private:
	std::vector<std::vector<int>> to;
	std::vector<State> partitions;
};

PartitionSolver<18> states;

const int ms = 38000;

long long dp[10][19][ms];

long long solve(long long x, int k) {
	long long ans = 0;
	std::vector<int> wtf;
	do {
		wtf.push_back((int)(x % 10));
		x /= 10;
	} while(x > 0);
	std::reverse(wtf.begin(), wtf.end());
	int rest = (int) wtf.size();
	int st = 0;
	for(auto ch : wtf) {
		rest--;
		for(int i = 0; i < ch; i++) {
			ans += dp[k][rest][states.add(st, i)];
		}
		st = states.add(st, ch);
		//states.getPermutation(st).print();
	}
	ans += dp[k][0][st];
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cerr << states.size() << '\n';
	for(int i = 0; i < states.size(); i++) {
		int best = states.getPermutation(i).best();
		assert(0 <= best && best <= 9);
		for(int k = best; k < 10; k++) {
			dp[k][0][i] = 1;
		}
	}
	for(int k = 0; k < 10; k++) {
		for(int i = 1; i < 19; i++) {
			for(int j = 0; j < states.size(); j++) {
				for(int ch = 0; ch <= 9; ch++) {
					dp[k][i][j] += dp[k][i-1][states.add(j, ch)];
				}
			}
		}
	}
	int n;
	std::cin >> n;
	while(n--) {
		long long l, r;
		int k;
		std::cin >> l >> r >> k;
		std::cout << solve(r, k) - solve(l-1, k) << '\n';
	}
}