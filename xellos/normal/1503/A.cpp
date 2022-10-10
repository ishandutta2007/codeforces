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
		int N;
		string S;
		cin >> N >> S;
		vector<int> val[2] = {vector<int>(N, 0), vector<int>(N, 0)};
		for(int i = 0; i < N; i++) if(S[i] == '1') val[0][i] = val[1][i] = 1;
		int n0 = 0;
		for(int i = 0, b = 1; i < N; i++) if(S[i] == '0') {
			n0++;
			val[0][i] = b;
			val[1][i] = -b;
			b = -b;
		}
		if(n0%2) {
			cout << "NO\n";
			continue;
		}
		int s = 0;
		for(int i = 0; i < N; i++) s += val[0][i];
		for(int i = N-1; i >= 0; i--) if(S[i] == '1' && s) {
			s -= 2;
			val[0][i] = val[1][i] = -1;
		}
		bool ok = true;
		for(int k = 0; k < 2; k++) {
			int cur = 0;
			for(int i = 0; i < N; i++) {
				cur += val[k][i];
				if(cur < 0) ok = false;
			}
		}
		if(ok) {
			cout << "YES\n";
			string ans[2];
			for(int k = 0; k < 2; k++)
				for(int i = 0; i < N; i++) ans[k] += (val[k][i] == 1) ? '(' : ')';
			cout << ans[0] << "\n" << ans[1] << "\n";
		}
		else cout << "NO\n";
	}
}

// look at my code
// my code is amazing