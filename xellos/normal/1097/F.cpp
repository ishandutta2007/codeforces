#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template<typename T, class _bset_array, int MX, int B>
struct precomputation {
	static constexpr array<_bset_array, MX+1> compute_init() {
		array<_bset_array, MX+1> init{};
		for(int i = 1; i <= MX; i++)
			for(int j = 1; j <= MX/i; j++)
				init[j*i][i/B] ^= static_cast<T>(1) << (i & (B-1));
		return init;
	}

	static constexpr array<_bset_array, MX+1> compute_coef() {
		array<_bset_array, MX+1> coef{};
		for(int i = 1; i <= MX; i++) {
			bool is_squarefree = true;
			for(int j = 2; j*j <= i; j++)
				is_squarefree &= (i % (j * j) != 0);
			if(is_squarefree)
				for(int j = 1; j <= MX/i; j++)
					coef[j][(i*j)/B] ^= static_cast<T>(1) << ((i*j) & (B-1));
		}
		return coef;
	}
};

class bset {
	static constexpr int MX = 7000, B = 64;
	using T = uint64_t;
	using _bset = array<T, MX/B+1>;

	static constexpr auto _init = precomputation<T, _bset, MX, B>::compute_init();
	static constexpr auto _coef = precomputation<T, _bset, MX, B>::compute_coef();

	_bset a{};

public:
	void set(int v) {
		a = _init[v];
	}

	bset & operator+=(const bset & V) {
		for(int i = 0; i <= MX/B; i++) a[i] ^= V[i];
		return *this;
	}

	void set_sum(const bset & V, const bset & W) {
		for(int i = 0; i <= MX/B; i++) a[i] = V[i] ^ W[i];
	}

	bset & operator*=(const bset & V) {
		for(int i = 0; i <= MX/B; i++) a[i] &= V[i];
		return *this;
	}

	void set_prod(const bset & V, const bset & W) {
		for(int i = 0; i <= MX/B; i++) a[i] = V[i] & W[i];
	}

	inline T operator[](size_t i) const {
		return a[i];
	}

	bool find(int v) const {
		T x = 0;
		for(int i = 0; i <= MX/B; i++) x ^= (_coef[v][i] & a[i]);
		bool ret = false;
		while(x > 0) {
			ret ^= x & 1;
			x /= 2;
		}
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector<bset> S(N+1);
	for(int i = 0; i < Q; i++) {
		int type, x, y, z, v;
		cin >> type;
		if(type == 1) {
			cin >> x >> v;
			S[x].set(v);
		}
		else if(type == 2) {
			cin >> x >> y >> z;
			S[x].set_sum(S[y], S[z]);
		}
		else if(type == 3) {
			cin >> x >> y >> z;
			S[x].set_prod(S[y], S[z]);
		}
		else if(type == 4) {
			cin >> x >> v;
			cout << S[x].find(v);
		}
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing