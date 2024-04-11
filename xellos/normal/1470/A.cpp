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
		vector<int> cnt(M, 0);
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			cnt[a-1]++;
		}
		vector<cat> C(M), A;
		for(int i = 0; i < M; i++) cin >> C[i];
		vector<int> A_id;
		for(int i = 0; i < M; i++) for(int j = 0; j < cnt[i]; j++) {
			A.push_back(C[i]);
			A_id.push_back(i);
		}
		cat sum_tot = 0, sum_C = 0, sum_A = 0;
		for(int i = 0; i < N; i++) sum_tot += A[i];
		cat ans = sum_tot;
		for(int k = 1, k_max = min(N, M); k <= min(N, M); k++) {
			// C[i] <= A[N-k+i] for 0 <= i < k
			// max b: C[k-1] <= A[N-b+k-1]
			auto it = lower_bound(begin(A), end(A), C[k-1]);
			k_max = min(k_max, N+k-1-int(it-begin(A)));
			if(k > k_max) break;
			sum_A += A[N-k];
			sum_C += C[k-1];
			ans = min(ans, sum_tot-sum_A+sum_C);
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing