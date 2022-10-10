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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M, T, W;
	cin >> N >> M >> T >> W;
	int B = 0;
	while(N%(2<<B) == 0) B++;
	T = min(T, 1<<B);
	map<int, int> A;
	vector<int> X(1<<B, 0), cnt(1<<B, 0);
	vector< vector<int> > V(B+1);
	for(int i = 0; i <= B; i++) V[i].resize(1<<i, -1);
	for(int i = 0; i < M; i++) {
		int pos, val;
		cin >> pos >> val;
		pos--;
		A[pos] = val;
		int id = pos&((1<<B)-1);
		X[id] ^= val;
		cnt[id]++;
		V[B][id] = (cnt[id] < (N>>B)) ? -1 : X[id];
	}
	int n_fail = 0, n_fixed = 0;
	if(T == (1<<B)) {
		for(int i = 0; i < (1<<B); i++) {
			if(V[B][i] > 0) n_fail++;
			if(V[B][i] >= 0) n_fixed++;
		}
	}
	else for(int b = B-1; b >= 0; b--) {
		for(int i = 0; i < (1<<b); i++) {
			int val_l = V[b+1][i], val_r = V[b+1][i+(1<<b)];
			if((T>>b)&1) {
				if(val_l == -1 || val_r == -1) V[b][i] = max(val_l, val_r);
				else {
					if(val_l != val_r) n_fail++;
					V[b][i] = val_l;
					n_fixed++;
				}
			}
			else {
				if(val_l == -1 || val_r == -1) V[b][i] = -1;
				else V[b][i] = val_l ^ val_r;
			}
		}
	}
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int pos, val;
		cat mod;
		cin >> pos >> val >> mod;
		pos--;
		int id = pos&((1<<B)-1);
		if(T == (1<<B)) {
			if(V[B][id] > 0) n_fail--;
			if(V[B][id] >= 0) n_fixed--;
		}
		else for(int b = B-1; b >= 0; b--) {
			int id1 = id&((1<<b)-1);
			int val_l = V[b+1][id1], val_r = V[b+1][id1+(1<<b)];
			if((T>>b)&1) {
				if(val_l != -1 && val_r != -1) {
					if(val_l != val_r) n_fail--;
					n_fixed--;
				}
			}
		}
		if(auto it = A.find(pos); it != end(A)) {
			X[id] ^= it->ss, cnt[id]--;
			if(val == -1) A.erase(it), M--;
			else it->ss = val;
		}
		else if(val != -1) A[pos] = val, M++;
		if(val != -1) X[id] ^= val, cnt[id]++;
		V[B][id] = (cnt[id] < (N>>B)) ? -1 : X[id];
		if(T == (1<<B)) {
			if(V[B][id] > 0) n_fail++;
			if(V[B][id] >= 0) n_fixed++;
		}
		else for(int b = B-1; b >= 0; b--) {
			int id1 = id&((1<<b)-1);
			int val_l = V[b+1][id1], val_r = V[b+1][id1+(1<<b)];
			if((T>>b)&1) {
				if(val_l == -1 || val_r == -1) V[b][id1] = max(val_l, val_r);
				else {
					if(val_l != val_r) n_fail++;
					V[b][id1] = val_l;
					n_fixed++;
				}
			}
			else {
				if(val_l == -1 || val_r == -1) V[b][id1] = -1;
				else V[b][id1] = val_l ^ val_r;
			}
		}
		if(n_fail) cout << "0\n";
		else cout << pw(2, (N-M-T+n_fixed)*W, mod) << "\n";
	}
}

// look at my code
// my code is amazing