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

class itree {
	int b;
	vector<cat> sum, mx, set_val;

	void push(int cur, int l, int r) {
		if(set_val[cur]) {
			if(cur < b) {
				set_val[2*cur] = max(set_val[2*cur], set_val[cur]);
				set_val[2*cur+1] = max(set_val[2*cur+1], set_val[cur]);
			}
			mx[cur] = set_val[cur];
			sum[cur] = (r-l) * set_val[cur];
			set_val[cur] = 0;
		}
	}

	void set(int l, int r, cat val_mx, int cur, int I_l, int I_r) {
		push(cur, I_l, I_r);
		l = max(l, I_l);
		r = min(r, I_r);
		if(l >= r) return;
		if(I_l == I_r-1) {
			sum[cur] = mx[cur] = max(mx[cur], val_mx);
			return;
		}
		if(l == I_l && r == I_r && mx[cur] <= val_mx) {
			set_val[cur] = val_mx;
			push(cur, I_l, I_r);
			return;
		}
		if(l == I_l && r == I_r) {
			push(2*cur+1, (I_l+I_r)/2, I_r);
			if(mx[2*cur+1] > val_mx) {
				push(2*cur, I_l, (I_l+I_r)/2);
				set(l, r, val_mx, 2*cur+1, (I_l+I_r)/2, I_r);
				sum[cur] = sum[2*cur] + sum[2*cur+1];
				mx[cur] = mx[2*cur];
				return;
			}
		}
		set(l, r, val_mx, 2*cur, I_l, (I_l+I_r)/2);
		set(l, r, val_mx, 2*cur+1, (I_l+I_r)/2, I_r);
		sum[cur] = sum[2*cur] + sum[2*cur+1];
		mx[cur] = mx[2*cur];
	}

	int get_le_id(int pos, cat val, int cur, int I_l, int I_r) {
		push(cur, I_l, I_r);
		if(pos <= I_l && mx[cur] <= val) return I_l;
		if(I_l == I_r-1) return I_r;
		int mid = (I_l+I_r)/2;
		int ans_r = get_le_id(pos, val, 2*cur+1, mid, I_r);
		if(mid <= pos) return ans_r;
		if(ans_r != mid) return ans_r;
		return get_le_id(pos, val, 2*cur, I_l, mid);
	}

	cat get_sum(int pos, int cur, int I_l, int I_r) {
		push(cur, I_l, I_r);
		if(pos >= I_r-1) return sum[cur];
		if(pos < I_l) return 0;
		int mid = (I_l+I_r)/2;
		return get_sum(pos, 2*cur, I_l, mid) + get_sum(pos, 2*cur+1, mid, I_r);
	}

	int get_sum_le(cat val, int cur, int I_l, int I_r, cat & sum_cur) {
		push(cur, I_l, I_r);
		if(I_l == I_r-1) {
			if(sum[cur]+sum_cur <= val) {
				sum_cur += sum[cur];
				return I_r;
			}
			return I_l;
		}
		int mid = (I_l+I_r)/2;
		push(2*cur, I_l, mid);
		if(sum[2*cur]+sum_cur > val) return get_sum_le(val, 2*cur, I_l, mid, sum_cur);
		sum_cur += sum[2*cur];
		return get_sum_le(val, 2*cur+1, mid, I_r, sum_cur);
	}

public:
	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		sum.resize(2*b, 0);
		mx.resize(2*b, 0);
		set_val.resize(2*b, 0);
	}

	void set(int l, int r, cat val_mx) {
		set(l, r, val_mx, 1, 0, b);
	}

	int get_le_id(int l, cat val) {
		// first r >= l s.t. [r] <= val
		return get_le_id(l, val, 1, 0, b);
	}

	pair<cat, int> get_sum_le(int l, cat val) {
		// val >= [l]
		// last r >= l s.t. [l:r] <= val
		cat sum_l = get_sum(l-1, 1, 0, b);
		cat sum_cur = 0;
		int ans = get_sum_le(val+sum_l, 1, 0, b, sum_cur);
		return {sum_cur-sum_l, ans};
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector<cat> A(N);
	itree I(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = N-1; i >= 0; i--) I.set(0, i+1, A[i]);
	for(int q = 0; q < Q; q++) {
		int tp, x;
		cat y;
		cin >> tp >> x >> y;
		if(tp == 1) {
			I.set(0, x, y);
			continue;
		}
		x--;
		int ans = 0;
		while(x < N) {
			x = I.get_le_id(x, y);
			if(x >= N) break;
			auto p = I.get_sum_le(x, y);
			if(p.ss >= N) p.ss = N;
			ans += p.ss-x;
			y -= p.ff;
			x = p.ss;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing