#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) {
	while(b != 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

const int ms = 42;

long long tmp[ms];

const int MOD = 1e9 + 7;
long long ans = 0;

struct Stack {
	long long v[ms], size;
	int f[ms];

	Stack() {
		size = 0;
	}

	void add(long long x) {
		for(int i = 0; i < size; i++) {
			tmp[i] = gcd(v[i], x);
		}
		f[size] = 1;
		tmp[size] = x;
		size++;
		int s = 0;
		for(int l = 0, r = 0; l < size; l = r) {
			int got = 0;
			v[s] = tmp[l];
			while(r < size && tmp[l] == tmp[r]) {
				got += f[r++];
			}
			f[s] = got;
			ans = (ans + v[s] % MOD * f[s]) % MOD;
			s++;
		}
		assert(s <= ms);
		size = s;
	}
};


const int mss = 100000;
long long a[mss];
Stack s[mss];
std::vector<int> edges[mss];

void dfs(int on, int par) {
	s[on].add(a[on]);
	for(auto to : edges[on]) {
		if(to != par) {
			s[to] = s[on];
			dfs(to, on);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0);
	std::cout << ans << '\n';
}