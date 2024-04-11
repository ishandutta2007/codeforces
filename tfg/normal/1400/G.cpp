#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

const int MOD = 998244353;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

const int ms = 300300;
const int me = 44;

modBase<> fat[ms], ifat[ms];
void initComb() {
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i;
	}
	ifat[ms-1] = fexp(fat[ms-1], MOD - 2);
	for(int i = ms-1; i > 0; i--) {
		ifat[i-1] = ifat[i] * i;
	}
}
modBase<> comb(int n, int a) { return a < 0 || a > n ? modBase<>(0) : fat[n] * ifat[a] * ifat[n-a]; }
modBase<> wtf[me][ms];
int lol[ms];

modBase<> solve(std::vector<std::pair<int, int>> &events, int verts, int left, int right) {
	int sum = 0;
	int on = 0;
	modBase<> ans(0);
	for(auto e : events) {
		{
			int rl = std::max(left, on);
			int rr = std::min(right, e.first-1) + 1;
			if(rl < rr) {
				// solve for range [rl, rr] with certain sum
				//std::cout << "has to solve range [" << rl << ", " << rr << ") with sum " << sum << " and verts " << verts << std::endl;
				for(int i = 0; i <= sum; i++) ans = ans + (wtf[verts+i][rr] - wtf[verts+i][rl]) * comb(sum, i);
			}
		}
		on = e.first;
		sum += e.second;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initComb();
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> edges(m);
	std::vector<bool> dirty(n, false);
	std::vector<int> step(n, -1);
	std::vector<int> l(n), r(n);
	for(int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i];
	}
	for(auto &edge : edges) {
		std::cin >> edge.first >> edge.second;
		edge.first--;
		edge.second--;
		dirty[edge.first] = dirty[edge.second] = true;
	}
	std::vector<int> special;
	for(int i = 0; i < n; i++) {
		if(dirty[i]) {
			special.push_back(i);
			continue;
		}
		lol[l[i]]++;
		lol[r[i]+1]--;
	}
	for(int i = 1; i < ms; i++) {
		lol[i] += lol[i-1];
	}
	for(int i = 0; i < me; i++) {
		for(int j = 1; j < ms; j++) {
			wtf[i][j] = comb(lol[j-1], j-1 - i) + wtf[i][j-1];
		}
	}
	modBase<> ans(0);
	for(int mask = 0; mask < (1 << m); mask++) {
		int bits = 0, verts = 0;
		int left = 0, right = n;
		for(int i = 0; i < m; i++) {
			if(mask & (1 << i)) {
				bits++;
				if(step[edges[i].first] != mask) {
					step[edges[i].first] = mask;
					verts++;
				}
				if(step[edges[i].second] != mask) {
					step[edges[i].second] = mask;
					verts++;
				}
				left = std::max(left, std::max(l[edges[i].first], l[edges[i].second]));
				right = std::min(right, std::min(r[edges[i].first], r[edges[i].second]));
			}
		}
		if(left > right) continue;
		std::vector<std::pair<int, int>> events;
		for(auto on : special) {
			if(step[on] != mask) {
				events.emplace_back(l[on], 1);
				events.emplace_back(r[on]+1, -1);
			}
		}
		events.emplace_back(n+1, 0);
		std::sort(events.begin(), events.end());
		//std::cout << "solving mask " << mask << std::endl;
		auto got = solve(events, verts, left, right);
		if(bits % 2 == 0) {
			ans = ans + got;
		} else {
			ans = ans - got;
		}
	}
	std::cout << ans-1 << '\n';
}