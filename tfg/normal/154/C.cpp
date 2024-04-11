#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> dist(0, (1 << 30) - 1);

const int ms = 10;

struct Hash {
	unsigned int v[ms];

	Hash() {
		for(int i = 0; i < ms; i++) {
			v[i] = 0;
		}
	}

	void randomize() {
		for(int i = 0; i < ms; i++) {
			v[i] = dist(rng);
		}
	}

	bool operator < (const Hash &o) const {
		for(int i = 0; i < ms; i++) {
			if(v[i] != o.v[i]) {
				return v[i] < o.v[i];
			}
		}
		return false;
	}

	bool operator == (const Hash &o) const {
		for(int i = 0; i < ms; i++) {
			if(v[i] != o.v[i]) {
				return false;
			}
		}
		return true;
	}

	Hash operator ^ (const Hash &o) const {
		Hash ans;
		for(int i = 0; i < ms; i++) {
			ans.v[i] = v[i] ^ o.v[i];
		}
		return ans;
	}
};

long long f(long long x) { return x * (x - 1) / 2; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<Hash> kek(n);
	for(int i = 0; i < n; i++) {
		kek[i].randomize();
	}
	std::vector<Hash> a(n);
	std::vector<std::pair<int, int>> edges;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges.emplace_back(u, v);
		a[u] = a[u] ^ kek[v];
		a[v] = a[v] ^ kek[u];
	}
	auto arr = a;
	std::sort(arr.begin(), arr.end());
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && arr[r] == arr[l]) {
			r++;
		}
		ans += f(r - l);
	}
	//std::cout << ans << '\n';
	for(auto e : edges) {
		int u = e.first, v = e.second;
		if((a[u] ^ a[v]) == (kek[u] ^ kek[v])) {
			//std::cout << "at " << u << ", " << v << '\n';
			ans++;
		} else if(a[u] == a[v]) {
			ans--;
		}
	}
	std::cout << ans << '\n';
}