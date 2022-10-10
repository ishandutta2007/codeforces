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
#define OVER9000 1234567890LL
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

void solve(int l, int r, auto & A, auto & R, auto & ans) {
	if(l >= r) return;
	for(int m = l+1; m < r; m++) if(A[m] == A[l]+1 && R[m]+1 >= r) {
		if(m > l+1 && !(R[l+1]+1 >= m && A[l+1] == 1)) continue;
		for(int k = l; k < m; k++) ans[k].push_back(A[l]);
		solve(l+1, m, A, R, ans);
		solve(m, r, A, R, ans);
		return;
	}
	for(int k = l; k < r; k++) ans[k].push_back(A[l]);
	solve(l+1, r, A, R, ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, P, M;
	cin >> N >> M >> P;
	vector<cat> A(N, 0);
	for(int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for(int j = 0; j < M; j++) if(S[j] == '1') A[i] |= 1LL<<j;
	}
	mt19937 rng(N+chrono::steady_clock::now().time_since_epoch().count());
	string ans = "";
	for(int i = 0; i < M; i++) ans += '0';
	int ans_sz = 0;
	for(int r = 0; r < 100; r++) {
		int id = uniform_int_distribution<int>(0, N-1)(rng);
		vector<int> id_c(M, -1);
		int C = 0;
		for(int i = 0; i < M; i++) if((A[id]>>i)&1) id_c[i] = C++;
		vector< vector<int> > cnt_sub(C+1, vector<int>(1<<C, 0));
		for(int i = 0; i < N; i++) {
			int b = 0;
			for(int j = 0; j < M; j++) if(((A[i]&A[id])>>j)&1) b |= 1<<id_c[j];
			cnt_sub[C][b]++;
		}
		for(int i = C-1; i >= 0; i--) {
			cnt_sub[i] = cnt_sub[i+1];
			for(int j = (1<<i); j < (1<<C); j++) cnt_sub[i][j-(1<<i)] += cnt_sub[i+1][j] * ((j>>i)&1);
		}
		for(int i = 0; i < (1<<C); i++) if(cnt_sub[0][i]*2 >= N) {
			if(__builtin_popcount(i) <= ans_sz) continue;
			ans_sz = __builtin_popcount(i);
			ans = "";
			for(int j = 0; j < M; j++) {
				if(id_c[j] >= 0 && ((i>>id_c[j])&1)) ans += '1';
				else ans += '0';
			}
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing