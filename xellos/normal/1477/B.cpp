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

struct itree {
	int b;
	vector<int> sum, upd_val;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		sum.resize(2*b, 0);
		upd_val.resize(2*b, -1);
	}

	void upd(int cur, int l, int r) {
		if(upd_val[cur] == -1) return;
		if(cur < b)
			upd_val[2*cur] = upd_val[2*cur+1] = upd_val[cur];
		sum[cur] = upd_val[cur] * (r-l);
		upd_val[cur] = -1;
	}

	void put(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur, l, r);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return;
		if(I_l == l && I_r == r) {
			upd_val[cur] = val;
			upd(cur, l, r);
			return;
		}
		put(I_l, I_r, val, 2*cur, l, (l+r)/2);
		put(I_l, I_r, val, 2*cur+1, (l+r)/2, r);
		sum[cur] = sum[2*cur] + sum[2*cur+1];
	}

	int get(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur, l, r);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return 0;
		if(I_l == l && I_r == r) return sum[cur];
		return get(I_l, I_r, 2*cur, l, (l+r)/2) + get(I_l, I_r, 2*cur+1, (l+r)/2, r);
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
		int N, Q;
		string S, F;
		cin >> N >> Q >> S >> F;
		vector<int> L(Q), R(Q);
		for(int i = 0; i < Q; i++) {
			cin >> L[i] >> R[i];
			L[i]--;
		}
		itree I(N);
		for(int i = 0; i < N; i++) if(F[i] == '1') I.put(i, i+1, 1);
		bool ok = true;
		for(int i = Q-1; i >= 0; i--) {
			int n1 = I.get(L[i], R[i]);
			int n0 = R[i]-L[i]-n1;
			if(n0 == n1) {
				ok = false;
				break;
			}
			if(n0 > n1) I.put(L[i], R[i], 0);
			else I.put(L[i], R[i], 1);
		}
		for(int i = 0; i < N; i++) if((S[i] == '1') != I.get(i, i+1)) {
			ok = false;
			break;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing