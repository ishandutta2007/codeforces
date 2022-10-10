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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> S(N);
		for(int i = 0; i < N; i++) cin >> S[i];
		cat MX = 5000000000000LL;
		cat ans_lt = -1, ans_ge = MX;
		while(ans_ge-ans_lt > 1) {
			vector<cat> A(N, 0);
			A[0] = (ans_lt+ans_ge)/2;
			bool ok = true;
			for(int i = 0; i < N; i++) {
				if(A[i] < S[i]-1) ok = false;
				for(int j = i+2; j <= min(N-1LL, i+S[i]); j++) A[j]++;
				if(i+1 < N) {
					A[i+1] += A[i]-S[i]+1;
					if(A[i+1] > MX) A[i+1] = MX;
				}
			}
			if(ok) ans_ge = (ans_lt+ans_ge)/2;
			else ans_lt = (ans_lt+ans_ge)/2;
		}
		cout << ans_ge << "\n";
	}
}

// look at my code
// my code is amazing