#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200;
//const int ms = 5 * 8 * 5 * 8 + 4;
const int MOD = 998244353;

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

template<const int n, const int m, class T = modBase<>>
struct Matrix {
	T v[n][m];
	
	Matrix(int d = 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				v[i][j] = T(0);
			}
			if(i < m) {
				v[i][i] = T(d);
			}
		}
	}
	
	template<int mm>
	Matrix<n, mm, T> operator *(const Matrix<m, mm, T> &o) {
		Matrix<n, mm, T> ans;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < mm; j++) {
				for(int k = 0; k < m; k++) {
					ans.v[i][j] = ans.v[i][j] + v[i][k] * o.v[k][j];
				}
			}
		}
		return ans;
	}
};

int c = 1;
int trie[ms][26];
int terminal[ms];

void add(const std::string &str) {
	int on = 0;
	for(auto ch : str) {
		//assert(c * c < ms);
		if(trie[on][ch - 'a'] == 0) trie[on][ch - 'a'] = c++;
		on = trie[on][ch - 'a'];
		//std::cout << on << '\n';
	}
	terminal[on]++;
}

int main() {
	//std::cout << "GOT HERE!" << std::endl;
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	//std::cout << ms << '\n';
	int n, m;
	std::cin >> n >> m;
	while(n--) {
		std::string str;
		std::cin >> str;
		add(str);
	}
	std::map<int, int> mp;
	mp[0] = 0;
	std::vector<int> q(1, 0);
	auto getId = [&](int id) {
		int i = id / c, j = id % c;
		if(i > j) std::swap(i, j);
		id = i * c + j;
		if(!mp.count(id)) {
			int sz = (int) mp.size();
			mp[id] = sz;
			assert(sz < ms);
			q.push_back(id);
		}
		return mp[id];
	};
	Matrix<ms, ms> mat(0);
	for(int wtf = 0; wtf < (int) q.size(); wtf++) {
		int i = q[wtf] / c, j = q[wtf] % c;
		for(int ch = 0; ch < 26; ch++) if(trie[i][ch] && trie[j][ch]) {
			int u = trie[i][ch], v = trie[j][ch];
			mat.v[getId(u * c + v)][getId(i * c + j)] += 1;
			mat.v[getId(0)][getId(i * c + j)] += terminal[u] * terminal[v];
			if(terminal[v]) mat.v[getId(u * c)][getId(i * c + j)] += terminal[v];
			if(terminal[u]) mat.v[getId(v)][getId(i * c + j)] += terminal[u];
		}
	}
	std::cout << fexp(mat, m).v[0][0] << '\n';
}