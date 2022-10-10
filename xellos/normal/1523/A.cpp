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
#define OVER9000 1234567890LL
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
		string S;
		cin >> N >> M >> S;
		vector<int> id1, x(N, M+10);
		for(int i = 0; i < N; i++) if(S[i] == '1') {
			id1.push_back(i);
			x[i] = 0;
		}
		int x_cur = 0;
		while(!id1.empty()) {
			vector<int> id1_nw;
			for(auto id : id1) for(int k = id-1; k <= id+1; k++) if(k >= 0 && k < N) {
				if(S[k] == '1') continue;
				if(k-1 >= 0 && x[k-1] <= x_cur) if(k+1 < N && x[k+1] <= x_cur) continue;
				x[k] = x_cur+1;
				S[k] = '1';
				id1_nw.push_back(k);
			}
			x_cur++;
			if(x_cur == M) break;
			id1 = id1_nw;
		}
		cout << S << "\n";
	}
}

// look at my code
// my code is amazing