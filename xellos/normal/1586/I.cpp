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

void DFS(int v, auto & G, auto & par) {
	for(auto s : G[v]) if(par[s] == -1) {
		par[s] = v;
		DFS(s, G, par);
	}
}

void setv(int r, int c, char val, auto & V) {
	if(V[r][c] != val && V[r][c] != '.') {
		cout << "NONE\n";
		exit(0);
	}
	V[r][c] = val;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	if(N%2) {
		cout << "NONE\n";
		return 0;
	}
	vector<string> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(V[i][j] != '.') {
		int i2 = j, j2 = i;
		setv(i2, j2, V[i][j], V);
		int i3 = N-1-j, j3 = N-1-i;
		setv(i3, j3, V[i][j], V);
		int i4 = N-1-i, j4 = N-1-j;
		setv(i4, j4, V[i][j], V);
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(V[i][j] != '.') {
		char inv = (V[i][j] == 'G') ? 'S' : 'G';
		if((i+j)%2 == 0) if(i+j < N) setv(0, i+j, (i%2) ? inv : V[i][j], V);
		if((i+j)%2 != 0) if(i <= j) setv(0, j-i, (i%2) ? inv : V[i][j], V);
	}
	for(int i = 0; i < N; i += 2) {
		if(V[0][i] != '.') setv(0, i+1, V[0][i], V);
		if(V[0][i+1] != '.') setv(0, i, V[0][i+1], V);
	}
	for(int i = 0; i < N; i++) if(V[0][i] == '.') {
		cout << "MULTIPLE\n";
		return 0;
	}
	for(int i = 0; i < N; i++) {
		setv(i, 0, V[0][i], V);
		setv(N-1-i, N-1, V[0][i], V);
		setv(N-1, N-1-i, V[0][i], V);
	}
	for(int i = 1; i < N; i++) for(int j = 1; j < N; j++) if((i+j)%2 != 0) {
		char inv = (V[i-1][j-1] == 'G') ? 'S' : 'G';
		setv(i, j, inv, V);
	}
	for(int i = 1; i < N; i++) for(int j = 0; j < N-1; j++) if((i+j)%2 == 0) {
		char inv = (V[i-1][j+1] == 'G') ? 'S' : 'G';
		setv(i, j, inv, V);
	}
	cout << "UNIQUE\n";
	for(int i = 0; i < N; i++) cout << V[i] << "\n";
}

// look at my code
// my code is amazing