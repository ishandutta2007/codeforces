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

struct itree {
	int b;
	vector<cat> sumv, minv, maxv, addv;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		sumv.resize(2*b, 0);
		minv.resize(2*b, 0);
		maxv.resize(2*b, 0);
		addv.resize(2*b, 0);
	}

	void add(int k, cat val) { add(b-k, b, val, 1, 0, b); }
	cat get(vector<cat> & A) {
		static cat S[105];
		S[0] = S[1] = 0;
		for(int i = 1; i < (int)A.size(); i++) S[i+1] = S[i] + A[i];
		return get(A.data(), S, 1, A.size(), 1, 0, b);
	}

private:
	void upd(int cur, int l, int r) {
		if(addv[cur] == 0) return;
		if(l+1 < r) {
			addv[2*cur] += addv[cur];
			addv[2*cur+1] += addv[cur];
		}
		sumv[cur] += addv[cur] * (r-l);
		minv[cur] += addv[cur], maxv[cur] += addv[cur];
		addv[cur] = 0;
	}

	void add(int I_l, int I_r, cat val, int cur, int l, int r) {
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addv[cur] += val;
			upd(cur, l, r);
			return;
		}
		upd(cur, l, r);
		if(I_l >= I_r) return;
		int m = (l+r)/2;
		add(I_l, I_r, val, 2*cur, l, m);
		add(I_l, I_r, val, 2*cur+1, m, r);
		sumv[cur] = sumv[2*cur] + sumv[2*cur+1];
		minv[cur] = minv[2*cur];
		maxv[cur] = maxv[2*cur+1];
	}

	cat get(const cat * A, const cat * S, int A_l, int A_r, int cur, int l, int r) {
		upd(cur, l, r);
		if(A_l == A_r) return 0;
		if(A[A_l] >= maxv[cur]) return sumv[cur] * (A_r-A_l);
		if(A[A_r-1] <= minv[cur]) return (S[A_r]-S[A_l]) * (r-l);
		cat ret = 0;
		while(A_l+8 <= A_r && A[A_l+7] <= minv[cur]) {
			ret += (S[A_l+8]-S[A_l]) * (r-l);
			A_l += 8;
		}
		while(A_l < A_r && A[A_l] <= minv[cur]) {
			ret += A[A_l] * (r-l);
			A_l++;
		}
		while(A_l <= A_r-8 && A[A_r-8] >= maxv[cur]) {
			ret += sumv[cur] * 8;
			A_r -= 8;
		}
		while(A_l < A_r && A[A_r-1] >= maxv[cur]) {
			ret += sumv[cur];
			A_r--;
		}
		if(l+1 < r && A_l < A_r) {
			int m = (l+r)/2;
			ret += get(A, S, A_l, A_r, 2*cur, l, m);
			ret += get(A, S, A_l, A_r, 2*cur+1, m, r);
		}
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M,Q;
	cin >> N >> M >> Q;
	vector<cat> A(N), B(M);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = N-1; i > 0; i--) A[i] -= A[i-1];
	for(int i = 0; i < M; i++) cin >> B[i];
	for(int i = M-1; i > 0; i--) B[i] -= B[i-1];
	cat ans_base = (N+M-1)*(A[0]+B[0]);
	for(int i = 1; i < N; i++) ans_base += (N-i) * A[i];
	for(int i = 1; i < M; i++) ans_base += (M-i) * B[i];
	itree I(M);
	for(int i = 1; i < M; i++) I.add(i, B[M-i]-B[M-1-i]);
	I.add(M-1, B[0]);
	for(int q = 0; q < Q; q++) {
		int tp,k,d;
		cin >> tp >> k >> d;
		if(tp == 1) {
			for(int i = N-k; i < N; i++) A[i] += d;
			if(N-k == 0) ans_base += (N+M-1) * d, k--;
			ans_base += 1LL*k*(k+1)/2 * d;
		}
		else {
			if(M-k == 0) ans_base += (N+M-1) * d, k--;
			ans_base += 1LL*k*(k+1)/2 * d;
			I.add(k, d);
		}
		cat ans = ans_base + I.get(A);
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing