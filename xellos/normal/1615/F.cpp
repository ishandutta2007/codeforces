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

constexpr cat MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		string S[2];
		cin >> N >> S[0] >> S[1];
		vector<cat> sum(4*N+1, 0), cnt(4*N+1, 0);
		cnt[2*N] = 1;
		for(int i = 0; i < N; i++) {
			vector<cat> sum_nw(4*N+1, 0), cnt_nw(4*N+1, 0);
			for(int a = 0; a < 2; a++) for(int b = 0; b < 2; b++) {
				if(S[0][i] == '1'-a || S[1][i] == '1'-b) continue;
				for(int j = 2*N-2*i; j <= 2*N+2*i; j++) {
					int k = (i%2) ? j-(a-b) : j+(a-b);
					cnt_nw[k] += cnt[j];
					if(cnt_nw[k] >= MOD) cnt_nw[k] -= MOD;
					sum_nw[k] = (sum_nw[k] + sum[j] + cnt[j] * abs(k-2*N)) % MOD;
				}
			}
			sum = sum_nw, cnt = cnt_nw;
		}
		cout << sum[2*N] << "\n";
	}
}

// look at my code
// my code is amazing