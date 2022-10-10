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
	fin() = default;

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
		string S[2];
		cin >> S[0] >> S[1];
		if(S[0] < S[1]) {
			cout << "0\n";
			continue;
		}
		cat ans = 1LL*N*N+1, cur = 0;
		vector<int> occ[26];
		for(int i = N-1; i >= 0; i--) occ[S[0][i]-'a'].push_back(i);
		int sz[26];
		for(int i = 0; i < 26; i++) sz[i] = occ[i].size();
		fin<int> F_sub[26];
		for(int i = 0; i < 26; i++) F_sub[i] = fin<int>(sz[i]+3, 0);
		for(int i = 0; i < N; i++) {
			int c = (S[1][i]-'a');
			for(int j = 0; j < c; j++) if(sz[j]) ans = min(ans, occ[j][sz[j]-1]-F_sub[j].get(sz[j]-1)+cur);
			if(sz[c] == 0) break;
			int p = occ[c][sz[c]-1]-F_sub[c].get(sz[c]-1);
			sz[c]--;
			cur += p;
			for(int j = 0; j < 26; j++) {
				int l = -1, r = sz[j];
				while(r-l > 1) {
					int m = (l+r)/2;
					if(occ[j][m]-F_sub[j].get(m) > p) l = m;
					else r = m;
				}
				if(l >= 0) {
					F_sub[j].put(l+1, -1);
					F_sub[j].put(0, 1);
				}
			}
		}
		if(ans == 1LL*N*N+1) ans = -1;
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing