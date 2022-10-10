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

cat P;

void solve(int v, int par, auto & G, auto & cnt_v, auto & cnt_e) {
	vector<int> son;
	for(auto s : G[v]) if(s != par) {
		solve(s, v, G, cnt_v, cnt_e);
		son.push_back(s);
	}
	int N = G.size(), M = son.size();
	vector< vector<cat> > prl(M+1, vector<cat>(N, 1));
	vector< vector<cat> > prr(M+1, vector<cat>(N, 1));
	for(int i = 0; i < M; i++) for(int l = 0; l < N; l++) prl[i+1][l] = prl[i][l] * cnt_v[son[i]][l] % P;
	for(int i = M-1; i >= 0; i--) for(int l = 0; l < N; l++) prr[i][l] = prr[i+1][l] * cnt_v[son[i]][l] % P;
	for(int i = 0; i < M; i++) {
		for(int l = 1; l < N; l++) cnt_e[son[i]][l] = prl[i][l] * prr[i+1][l] % P;
		for(int l = 2; l < N; l++) {
			cnt_e[son[i]][l] += cnt_e[son[i]][l-1];
			if(cnt_e[son[i]][l] >= P) cnt_e[son[i]][l] -= P;
		}
	}
	for(int l = 0; l < N-1; l++) cnt_v[v][l+1] = prl[M][l+1];
	for(int i = 0; i < M; i++) for(int l = 0; l < N-1; l++)
		cnt_v[v][l+1] = (cnt_v[v][l+1] + cnt_e[son[i]][l] * (cnt_v[son[i]][l+1]-cnt_v[son[i]][l]+P)) % P;
	for(int i = 0; i < N-1; i++) {
		cnt_v[v][i+1] += cnt_v[v][i];
		if(cnt_v[v][i+1] >= P) cnt_v[v][i+1] -= P;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N >> P;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<cat> fac(N, 1), fac_inv(N, 1);
	for(int i = 1; i < N; i++) {
		fac[i] = fac[i-1] * i % P;
		fac_inv[i] = fac_inv[i-1] * pw(i, P-2, P) % P;
	}
	vector< vector<cat> > cnt_v(N, vector<cat>(N, 0));
	vector< vector<cat> > cnt_e(N, vector<cat>(N, 0));
	vector<cat> ans_r(N, 1);
	for(auto s : G[0]) solve(s, 0, G, cnt_v, cnt_e);
	for(int i = 0; i < N; i++) {
		for(auto s : G[0]) ans_r[i] = ans_r[i] * cnt_v[s][i] % P;
		ans_r[i] = ans_r[i] * fac_inv[i] % P;
		for(int j = 0; j < i; j++) ans_r[i] = (ans_r[i] - ans_r[j] * fac_inv[i-j]) % P;
	}
	for(int i = 1; i < N; i++) {
		ans_r[i] = ans_r[i] * fac[i] % P;
		if(ans_r[i] < 0) ans_r[i] += P;
		cout << ans_r[i] << ((i == N-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing