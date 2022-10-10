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
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<string> S(N);
		for(int i = 0; i < N; i++) cin >> S[i];
		if(N%3) {
			string emp;
			for(int i = 0; i < M; i++) emp += '.';
			S.push_back(emp);
			if(N%3 == 1) S.insert(begin(S), emp);
		}
		for(int i = 1; i < (int)S.size(); i += 3) {
			for(int j = 0; j < M; j++) if(S[i][j] == '.') S[i][j] = '#';
			if(i > 1) {
				bool found = false;
				for(int j = 0; j < M; j++) {
					if(S[i-1][j] == 'X' && !found) S[i-2][j] = '#', found = true;
					if(S[i-2][j] == 'X' && !found) S[i-1][j] = '#', found = true;
				}
				if(!found) S[i-1][0] = S[i-2][0] = '#';
			}
		}
		for(int i = 0; i < (int)S.size(); i++) for(int j = 0; j < M; j++) if(S[i][j] == '#') S[i][j] = 'X';
		for(int i = 0; i < N; i++) cout << S[i + (N%3 == 1)] << "\n";
	}
}

// look at my code
// my code is amazing