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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N,M;
		cin >> N >> M;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		sort(begin(A), end(A));
		vector< pair<int,int> > B;
		for(int i = 0; i < M; i++) {
			int l,r;
			cin >> l >> r;
			auto it = lower_bound(begin(A), end(A), l);
			if(it != end(A) && *it <= r) continue;
			B.push_back({l,r});
		}
		sort(begin(B), end(B));
		M = B.size();
		if(M == 0) {
			cout << "0\n";
			continue;
		}

		{
			int id_r = M-1;
			vector< pair<int,int> > B_nw = {B[M-1]};
			for(int i = M-2; i >= 0; i--) {
				if(B[id_r].ss <= B[i].ss) continue;
				if(B[id_r].ff == B[i].ff) B_nw.back() = B[i];
				else B_nw.push_back(B[i]);
				id_r = i;
			}
			reverse(begin(B_nw), end(B_nw));
			B = B_nw;
			M = B.size();
		}
		if(M == 0) {
			cout << "0\n";
			continue;
		}

		vector<int> lft(M), rt(M);
		for(int i = 0, pt_lft = -1; i < M; i++) {
			while(pt_lft+1 < N && A[pt_lft+1] < B[i].ff) pt_lft++;
			lft[i] = pt_lft, rt[i] = pt_lft+1;
		}

		vector<cat> dp_lft[2];
		for(int k = 0; k < 2; k++) dp_lft[k] = vector<cat>(M, OVER9000);
		vector<cat> dp_rt[2];
		for(int k = 0; k < 2; k++) dp_rt[k] = vector<cat>(M, OVER9000);

		if(lft[0] >= 0) dp_lft[0][0] = B[0].ff-A[lft[0]], dp_lft[1][0] = 2LL*(B[0].ff-A[lft[0]]);
		if(rt[0] < N) dp_rt[0][0] = A[rt[0]]-B[0].ss, dp_rt[1][0] = 2LL*(A[rt[0]]-B[0].ss);

		for(int i = 1; i < M; i++) {
			// dp_lft[0][i] je cena ak pritiahnem A[pt_lft] k B[i].ff
			if(lft[i] >= 0) { // solve dp_lft[k][i]
				if(lft[i-1] == lft[i]) {
					dp_lft[0][i] = min(dp_lft[0][i], dp_lft[0][i-1] + B[i].ff-B[i-1].ff);
					dp_lft[1][i] = min(dp_lft[1][i], dp_lft[1][i-1] + 2LL*(B[i].ff-B[i-1].ff));
				}
				else {
					dp_lft[0][i] = min(dp_lft[0][i], min(dp_lft[0][i-1],dp_lft[1][i-1]) + B[i].ff-A[lft[i]]);
					dp_lft[1][i] = min(dp_lft[1][i], min(dp_lft[0][i-1],dp_lft[1][i-1]) + 2LL*(B[i].ff-A[lft[i]]));
					if(rt[i-1] == lft[i]) {
						dp_lft[0][i] = min(dp_lft[0][i], dp_rt[1][i-1] + B[i].ff-A[lft[i]]);
						dp_lft[1][i] = min(dp_lft[1][i], dp_rt[0][i-1] + 2LL*(B[i].ff-A[lft[i]]));
					}
					else {
						dp_lft[0][i] = min(dp_lft[0][i], min(dp_rt[0][i-1],dp_rt[1][i-1]) + B[i].ff-A[lft[i]]);
						dp_lft[1][i] = min(dp_lft[1][i], min(dp_rt[0][i-1],dp_rt[1][i-1]) + 2LL*(B[i].ff-A[lft[i]]));
					}
				}
			}
			if(rt[i] < N) { // solve dp_rt[k][i]
				if(rt[i-1] == rt[i]) {
					dp_rt[0][i] = min(dp_rt[0][i], dp_rt[0][i-1]);
					dp_rt[1][i] = min(dp_rt[1][i], dp_rt[1][i-1]);
				}
				else {
					dp_rt[0][i] = min(dp_rt[0][i], min(dp_rt[0][i-1],dp_rt[1][i-1]) + A[rt[i]]-B[i].ss);
					dp_rt[1][i] = min(dp_rt[1][i], min(dp_rt[0][i-1],dp_rt[1][i-1]) + 2LL*(A[rt[i]]-B[i].ss));
				}
				dp_rt[0][i] = min(dp_rt[0][i], min(dp_lft[0][i-1],dp_lft[1][i-1]) + A[rt[i]]-B[i].ss);
				dp_rt[1][i] = min(dp_rt[1][i], min(dp_lft[0][i-1],dp_lft[1][i-1]) + 2LL*(A[rt[i]]-B[i].ss));
			}
		}
		cout << min(min(dp_lft[0][M-1], dp_lft[1][M-1]), min(dp_rt[0][M-1], dp_rt[1][M-1])) << "\n";
	}
}

// look at my code
// my code is amazing