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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<int> val[3] = {vector<int>(N*N), vector<int>(N*N), vector<int>(N*N)};
		for(int i = 0; i < N*N; i++) {
			val[0][i] = i/N;
			val[1][i] = i%N;
			cin >> val[2][i];
			val[2][i]--;
		}
		int P[3] = {0, 1, 2};
		int sh[3] = {0, 0, 0};
		string S;
		cin >> S;
		for(int i = 0; i < M; i++) {
			if(S[i] == 'R') sh[P[1]]++;
			if(S[i] == 'L') sh[P[1]]--;
			if(S[i] == 'D') sh[P[0]]++;
			if(S[i] == 'U') sh[P[0]]--;
			if(S[i] == 'I') swap(P[1], P[2]);
			if(S[i] == 'C') swap(P[0], P[2]);
		}
		vector< vector<int> > ans(N, vector<int>(N));
		for(int i = 0; i < N*N; i++) {
			int v[3] = {val[P[0]][i]+sh[P[0]], val[P[1]][i]+sh[P[1]], val[P[2]][i]+sh[P[2]]};
			v[0] %= N;
			if(v[0] < 0) v[0] += N;
			v[1] %= N;
			if(v[1] < 0) v[1] += N;
			v[2] %= N;
			if(v[2] < 0) v[2] += N;
			ans[v[0]][v[1]] = v[2];
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				cout << ans[i][j]+1 << ((j == N-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing