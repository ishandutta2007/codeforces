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
#define OVER9000 1234567890123456789LL
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

template <typename T>
class maxfin {
	vector<T> node_val;
	T init_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	maxfin(int N, T init_val_) : init_val{init_val_} {
		node_val.resize(N+10, init_val_);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = max(node_val[i], val);
	}

	T get_max(int pos) {
		T ret = init_val;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, node_val[i]);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	string S;
	cin >> S;
	int L = S.length();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()+L);
	vector<int> val(L+1, 0);
	for(int i = 0; i < L; i++) val[i+1] = val[i] + (S[i] == '(' ? 1 : -1);
	int N = 0;
	for(int i = 1; i <= L; i++) if(val[i] < val[N]) N = i;
	if(N == 0) {
		for(int i = 0; i < val[L]; i++) cout << '(';
		cout << '\n';
		return 0;
	}
	maxfin F_val(N, -L);
	vector< vector<int> > id_by_val(2*L+1);
	for(int i = 0; i <= N; i++) id_by_val[val[i]+L].push_back(i);
	vector< vector<int> > best_by_val(2*L+1);
	vector<int> nxt(N), n_open(N);
	vector<int> H[40][2];
	vector<int> H_nxt[40];
	for(int k = 0; k < 80; k++) H[k/2][k%2].resize(N);
	for(int k = 0; k < 40; k++) H_nxt[k].resize(N);
	cat MOD[2] = {1000000007, 1000000009};
	cat p = 999983;
	cat pp[40][2];
	for(int m = 0; m < 2; m++) {
		pp[0][m] = p;
		for(int k = 1; k < 40; k++) pp[k][m] = pp[k-1][m] * pp[k-1][m] % MOD[m];
	}
	for(int i = N-1; i >= 0; i--) {
		F_val.put(i, val[i]);
		auto id_lt_val = *(lower_bound(begin(id_by_val[val[i]-1+L]), end(id_by_val[val[i]-1+L]), i));
		int mx_val = F_val.get_max(id_lt_val-1);
		n_open[i] = mx_val-val[i];
		nxt[i] = i+1;
		int ge = -1, lt = best_by_val[mx_val+L].size();
		while(lt-ge > 1) {
			int mid = (lt+ge)/2;
			if(best_by_val[mx_val+L][mid] >= id_lt_val) ge = mid;
			else lt = mid;
		}
		if(lt != (int)best_by_val[mx_val+L].size()) nxt[i] = best_by_val[mx_val+L][lt]+1;
		H_nxt[0][i] = nxt[i];
		for(int k = 1; k < 40; k++) {
			if(H_nxt[k-1][i] < N) H_nxt[k][i] = H_nxt[k-1][H_nxt[k-1][i]];
			else H_nxt[k][i] = N+1;
		}
		for(int m = 0; m < 2; m++) {
			H[0][m][i] = n_open[i]+1;
			for(int k = 1; k < 40; k++) {
				if(H_nxt[k][i] > N) break;
				H[k][m][i] = (H[k-1][m][i] * pp[k-1][m] + H[k-1][m][H_nxt[k-1][i]]) % MOD[m];
			}
		}
		while(!best_by_val[val[i]+L].empty()) {
			int a = i, b = best_by_val[val[i]+L].back();
			for(int k = 39; k >= 0; k--) if(a < N && b < N && H_nxt[k][a] <= N && H_nxt[k][b] <= N)
				if((H[k][0][a]-H[k][0][b])%MOD[0] == 0 && (H[k][1][a]-H[k][1][b])%MOD[1] == 0)
					a = H_nxt[k][a], b = H_nxt[k][b];
			if(a == N || (b != N && n_open[a] > n_open[b])) best_by_val[val[i]+L].pop_back();
			else break;
		}
		best_by_val[val[i]+L].push_back(i);
	}
	int cur = 0;
	while(cur < N) {
		for(int i = 0; i < n_open[cur]; i++) cout << '(';
		cout << ')';
		cur = nxt[cur];
	}
	for(int i = 0; i < val[L]-val[N]; i++) cout << '(';
	cout << '\n';
}

// look at my code
// my code is amazing