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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

struct range {
	int l,r;
	cat cost;

	bool operator<(const range & b) const {
		return this->r < b.r;
	}
};

struct itree {
	int b;
	vector<cat> mx_A, mx_B, ans;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mx_A.resize(2*b, -OVER9000);
		mx_B.resize(2*b, -OVER9000);
		ans.resize(2*b, -OVER9000);
	}

	void put_A(int pos, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		mx_A[cur] = max(mx_A[cur], val);
		if(l+1 == r) return;
		int mid = (l+r)/2;
		if(pos < mid) put_A(pos, val, 2*cur, l, mid);
		else put_A(pos, val, 2*cur+1, mid, r);
	}

	void put_B(int pos, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		mx_B[cur] = max(mx_B[cur], val);
		if(l+1 == r) return;
		int mid = (l+r)/2;
		if(pos < mid) put_B(pos, val, 2*cur, l, mid);
		else put_B(pos, val, 2*cur+1, mid, r);
	}

	cat get_max_A(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return -OVER9000;
		if(I_l == l && I_r == r) return mx_A[cur];
		int mid = (l+r)/2;
		return max(get_max_A(I_l, I_r, 2*cur, l, mid), get_max_A(I_l, I_r, 2*cur+1, mid, r));
	}

	cat get_max_B(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return -OVER9000;
		if(I_l == l && I_r == r) return mx_B[cur];
		int mid = (l+r)/2;
		return max(get_max_B(I_l, I_r, 2*cur, l, mid), get_max_B(I_l, I_r, 2*cur+1, mid, r));
	}

	void precalc_ans(int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) {
			ans[cur] = mx_A[cur] + mx_B[cur];
			return;
		}
		int mid = (l+r)/2;
		precalc_ans(2*cur, l, mid);
		precalc_ans(2*cur+1, mid, r);
		ans[cur] = max(mx_A[2*cur] + mx_B[2*cur+1], max(ans[2*cur], ans[2*cur+1]));
	}

	struct info {
		cat ans, mx_A, mx_B;
	};

	info get_ans(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return {-OVER9000, -OVER9000, -OVER9000};
		if(I_l == l && I_r == r) return {ans[cur], mx_A[cur], mx_B[cur]};
		int mid = (l+r)/2;
		info ret_l = get_ans(I_l, I_r, 2*cur, l, mid);
		info ret_r = get_ans(I_l, I_r, 2*cur+1, mid, r);
		return {
			.ans = max(ret_l.mx_A+ret_r.mx_B, max(ret_l.ans, ret_r.ans)),
			.mx_A = max(ret_l.mx_A, ret_r.mx_A),
			.mx_B = max(ret_l.mx_B, ret_r.mx_B)
		};
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M;
	cin >> N >> M;
	vector<cat> A0[3], S0[3];
	for(int k = 0; k < 3; k++) {
		A0[k].resize(N);
		for(int i = 0; i < N; i++) cin >> A0[k][i];
		S0[k].resize(N+1, 0);
		for(int i = 0; i < N; i++) S0[k][i+1] = S0[k][i] + A0[k][i];
	}
	vector<cat> A(N), B(N);
	for(int i = 0; i < N; i++) A[i] = S0[0][i+1] - S0[1][i];
	for(int i = 0; i < N; i++) B[i] = S0[2][N] - S0[2][i] + S0[1][i+1];
	vector<range> R(M);
	for(int i = 0; i < M; i++) {
		cin >> R[i].l >> R[i].r >> R[i].cost;
		R[i].l--;
	}
	sort(begin(R), end(R));
	itree I(N+1);
	for(int i = 0; i < N; i++) I.put_A(i, A[i]);
	for(int i = 0; i < M; i++) {
		cat c = I.get_max_A(R[i].l, R[i].r) - R[i].cost;
		I.put_A(R[i].r, c);
	}
	for(int i = 0; i < N; i++) I.put_B(i, B[i]);
	I.precalc_ans();
	cat ans = -OVER9000;
	for(int i = 0; i < M; i++)
		ans = max(ans, I.get_ans(R[i].l, R[i].r).ans - R[i].cost);
	cout << ans << "\n";
}

// look at my code
// my code is amazing