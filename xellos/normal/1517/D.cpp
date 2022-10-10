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
	int N, M, K;
	cin >> N >> M >> K;
	if(K%2) {
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++) cout << -1 << ((j == M-1) ? "\n" : " ");
		return 0;
	}
	K /= 2;
	vector< vector<int> > R(N, vector<int>(M-1));
	for(int i = 0; i < N; i++) for(int j = 0; j < M-1; j++) cin >> R[i][j];
	vector< vector<int> > D(N-1, vector<int>(M));
	for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++) cin >> D[i][j];
	vector< vector<int> > path(N, vector<int>(M, 0));
	for(int k = 1; k <= K; k++) {
		vector< vector<int> > path_nw(N, vector<int>(M, OVER9000));
		for(int r = 1; r < N; r++) for(int c = 0; c < M; c++)
			path_nw[(r-1)][c] = min(path_nw[r-1][c], path[r][c] + D[r-1][c]);
		for(int r = 0; r < N-1; r++) for(int c = 0; c < M; c++)
			path_nw[(r+1)][c] = min(path_nw[r+1][c], path[r][c] + D[r][c]);
		for(int r = 0; r < N; r++) for(int c = 1; c < M; c++)
			path_nw[r][c-1] = min(path_nw[r][c-1], path[r][c] + R[r][c-1]);
		for(int r = 0; r < N; r++) for(int c = 0; c < M-1; c++)
			path_nw[r][c+1] = min(path_nw[r][c+1], path[r][c] + R[r][c]);
		path = path_nw;
	}
	for(int r = 0; r < N; r++) for(int c = 0; c < M; c++)
		cout << 2*path[r][c] << ((c == M-1) ? "\n" : " ");
}

// look at my code
// my code is amazing