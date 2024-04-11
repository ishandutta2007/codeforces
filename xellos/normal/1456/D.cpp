// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

struct range {
	cat l, r;
	bool empty;

	range() : l(0), r(0), empty(true) {}
	range(cat l_, cat r_, bool empty_) : l(l_), r(r_), empty(empty_) {}

	range unify(range R) {
		if(this->empty) return R;
		if(R.empty) return *this;
		return {min(this->l, R.l), max(this->r, R.r), false};
	}

	range intersect(range R) {
		if(this->empty || R.empty) return range();
		range ret = {max(this->l, R.l), min(this->r, R.r), false};
		if(ret.l > ret.r) return range();
		return ret;
	}

	bool contains(cat pos) {
		return (!this->empty && this->l <= pos && pos <= this->r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<cat> T(N+1, 0), X(N+1, 0);
	for(int i = 0; i < N; i++) cin >> T[i+1] >> X[i+1];
	vector<range> S_me[2] = {vector<range>(N+1), vector<range>(N+1)};
	vector<range> S_cl(N+1);
	S_me[0][0] = {0, 0, 0};
	for(int i = 0; i < N; i++) {
		if(!S_cl[i].empty && abs(X[i]-X[i+1]) <= T[i+1]-T[i]) {
			// I took the last, I'm taking the next
			S_cl[i+1] = S_cl[i+1].unify(S_cl[i]);
			cat D = (T[i+1]-T[i] - abs(X[i]-X[i+1])) / 2;
			range S = {min(X[i], X[i+1])-D, max(X[i], X[i+1])+D, false};
			S_cl[i+1] = S_cl[i+1].unify(S);
		}
		for(int k = 0; k < 2; k++) if(!S_me[k][i].empty) {
			// clone took the last, clone's taking the next
			cat T_min = T[i];
			if(X[i+1] < S_me[k][i].l) T_min += S_me[k][i].l-X[i+1];
			if(X[i+1] > S_me[k][i].r) T_min += X[i+1]-S_me[k][i].r;
			if(T_min <= T[i+1]) S_me[0][i+1] = S_me[0][i+1].unify({X[i+1]-(T[i+1]-T_min), X[i+1]+(T[i+1]-T_min), false});
		}
		if(!S_cl[i].empty) {
			// I took the last, clone's taking the next
			if(S_cl[i].contains(X[i+1])) S_me[1][i+1] = S_me[1][i+1].unify({X[i]-(T[i+1]-T[i]), X[i]+(T[i+1]-T[i]), false});
			else {
				cat T_min = T[i] + abs(X[i+1]-X[i]);
				if(T_min <= T[i+1]) S_me[0][i+1] = S_me[0][i+1].unify({X[i+1]-(T[i+1]-T_min), X[i+1]+(T[i+1]-T_min), false});
			}
		}
		for(int k = 0; k < 2; k++) if(!S_me[k][i].empty) {
			// clone took the last, I'm taking the next
			range S = S_me[k][i].intersect({X[i+1]-(T[i+1]-T[i]), X[i+1]+(T[i+1]-T[i]), false});
			if(!S.empty) {
				cat DL = (T[i+1]-T[i] - abs(S.l-X[i+1])) / 2;
				cat DR = (T[i+1]-T[i] - abs(S.r-X[i+1])) / 2;
				cat T_min = T[i];
				if(X[i+1] < S_me[k][i].l) T_min += S_me[k][i].l-X[i+1];
				if(X[i+1] > S_me[k][i].r) T_min += X[i+1]-S_me[k][i].r;
				cat D = (T[i+1]-T_min) / 2;
				S = {min(S.l-DL, X[i+1]-D), max(S.r+DR, X[i+1]+D), false};
				S_cl[i+1] = S_cl[i+1].unify(S);
			}
		}
	}
	if(!S_me[0][N].empty || !S_me[1][N].empty || !S_cl[N].empty) cout << "YES\n";
	else cout << "NO\n";
}

// look at my code
// my code is amazing