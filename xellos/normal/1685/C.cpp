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
		string S;
		cin >> N >> S;
		vector<int> D(2*N+1, 0);
		for(int i = 0; i < 2*N; i++) {
			if(S[i] == '(') D[i+1] = D[i]+1;
			else D[i+1] = D[i]-1;
		}
		int mi_l = -1, mi_r = 2*N+1;
		for(int i = 1; i < 2*N; i++) if(D[i] < 0) {
			mi_l = i;
			break;
		}
		for(int i = 1; i < 2*N; i++) if(D[i] < 0) mi_r = i;
		if(mi_l == -1) {
			cout << "0\n";
			continue;
		}
		int rev_l = 0, rev_r = 2*N;
		for(int i = 0; i < mi_l; i++) if(D[i] > D[rev_l]) rev_l = i;
		for(int i = mi_r+1; i <= 2*N; i++) if(D[i] > D[rev_r]) rev_r = i;
		bool ok1 = true;
		for(int i = rev_l; i <= rev_r; i++) if(D[i] > D[rev_l]+D[rev_r]) ok1 = false;
		if(ok1) {
			cout << "1\n";
			cout << rev_l+1 << " " << rev_r << "\n";
			continue;
		}
		cout << "2\n";
		int mx = 0;
		for(int i = 0; i <= 2*N; i++) if(D[i] > D[mx]) mx = i;
		// mx > 0
		cout << "1 " << mx << "\n" << mx+1 << " " << 2*N << "\n";
	}
}

// look at my code
// my code is amazing