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

constexpr cat MOD = 1000000007;

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
			if(node_val[i] >= MOD) node_val[i] -= MOD;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
			if(ret >= MOD) ret -= MOD;
		}
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
		vector< pair<int,int> > A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i].ff;
			A[i].ss = -i;
		}
		sort(begin(A), end(A));
		vector<int> P(N);
		for(int i = 0; i < N; i++) P[-A[i].ss] = i;
		vector<cat> cnt_subseq(N), sum_subseq(N);
		fin<cat> F_cnt(N, 0), F_sum(N, 0);
		for(int i = 0; i < N; i++) {
			cnt_subseq[i] = 1 + F_cnt.get(P[i]);
			if(cnt_subseq[i] >= MOD) cnt_subseq[i] -= MOD;
			F_cnt.put(P[i], cnt_subseq[i]);
			sum_subseq[i] = cnt_subseq[i] + F_sum.get(P[i]);
			if(sum_subseq[i] >= MOD) sum_subseq[i] -= MOD;
			F_sum.put(P[i], sum_subseq[i]);
		}
		vector< pair<int,int> > st;
		vector<int> last_gt(N, N);
		for(int i = N-1; i >= 0; i--) {
			if(!st.empty()) {
				auto it = lower_bound(begin(st), end(st), make_pair(P[i],-1));
				if(it != end(st)) last_gt[i] = it->ss;
			}
			if(st.empty() || st.back().ff < P[i]) st.push_back({P[i],i});
		}
		vector<cat> dp;
		cat ans = 0;
		fin<cat> F(N, 0);
		for(int i = N-1; i >= 0; i--) {
			if(last_gt[i] != N) {
				int up = P[last_gt[i]];
				ans = (ans + sum_subseq[i] * (1+F.get(N-2-up))) % MOD;
				cat cnt = F.get(N-1-P[i]) - F.get(N-2-up);
				if(cnt >= MOD) cnt -= MOD;
				if(cnt < 0) cnt += MOD;
				F.put(N-1-P[i], cnt);
			}
			else {
				F.put(N-1-P[i], 1);
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing