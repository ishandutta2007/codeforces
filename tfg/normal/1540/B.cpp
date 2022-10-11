#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	//void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

template <class T>
class FenwickTree {
public:
	void init(int _n) {
		this->n = _n;
		bit.assign(n + 1, 0);
	}

	void init(const std::vector<T> &a) {
		n = a.size();
		bit.assign(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
			if(i + (i & -i) <= n) {
				bit[i + (i & -i)] += bit[i];
			}
		}
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};

const int ms = 202;

modBase<> tree[ms];
modBase<> pairTree[ms][ms][2];
bool vis1[ms], vis[ms][ms][2];
std::vector<int> edges[ms], graph[ms];

modBase<> solvePair(int on1, int on2, int mask) {
	modBase<> &ans = pairTree[on1][on2][mask];
	if(vis[on1][on2][mask]) return ans;
	ans = 0;
	vis[on1][on2][mask] = true;
	if(mask == 0) {
		// has choice
		ans += solvePair(on1, on2, 1) + solvePair(on2, on1, 1);
		for(auto to : graph[on1]) {
			ans += solvePair(to, on2, 0);
		}
		for(auto to : graph[on2]) {
			ans += solvePair(on1, to, 0);
		}
		ans *= (MOD + 1) / 2;
	} else {
		// no choice, on1 fixed
		if(on1 < on2) ans += 1;
		for(auto to : graph[on2]) {
			ans += solvePair(on1, to, 1);
		} 
	}
	return ans;
}

modBase<> solve(int on) {
	modBase<> &ans = tree[on];
	if(vis1[on]) return ans;
	vis1[on] = true;
	ans = solvePair(on, on, 1);
	for(int i = 0; i < (int) graph[on].size(); i++) {
		ans += solve(graph[on][i]);
		for(int j = i+1; j < (int) graph[on].size(); j++) {
			ans += solvePair(graph[on][i], graph[on][j], 0);
		}
	}
	return ans;
}

void pre(int on, int par) {
	graph[on].clear();
	for(auto to : edges[on]) {
		if(to == par) continue;
		graph[on].push_back(to);
		pre(to, on);
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u = n - u, v = n - v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	modBase<> ans(0);
	for(int root = 0; root < n; root++) {
		pre(root, -1);
		memset(vis, 0, sizeof vis);
		memset(vis1, 0, sizeof vis1);
		//std::cout << "at " << root << " got " << solve(root) << '\n';
		ans += solve(root);
	}
	std::cout << ans / n << '\n';
}