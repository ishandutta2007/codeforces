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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, K;
	cin >> N >> K;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(begin(A), end(A));
	cat ans_bad = 0;
	for(int i = 0, n_min = K+1, val_min = 0; i < N; i++) {
		ans_bad += val_min * A[i];
		n_min--;
		if(n_min == 0) {
			n_min = K+1;
			val_min++;
		}
	}
	if(K == 0 || A[N-1] <= 0) {
		cout << ans_bad << "\n";
		return 0;
	}
	cat cost_pos = 0, sum_pos = 0;
	while(N > 0 && A[N-1] > 0) {
		cost_pos += sum_pos;
		sum_pos += A[N-1];
		N--;
	}
	cat ans = ans_bad;
	vector<cat> S(N+1, 0);
	for(int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
	vector<cat> cost_pref(N+1, 0);
	for(int X = 1; X <= N; X++) if(1LL*(K+1)*X <= N) {
		cost_pref[X] = cost_pref[X-1];
		cost_pref[X] += (S[(X)*(K+1)] - S[(X-1)*(K+1)]) * (X-1);
	}
	vector<cat> SP(N+1, 0);
	for(int i = 0; i < N; i++) SP[i+1] = SP[i] + A[i] * i;
	for(int X = 0; X <= N; X++) {
		cat cost_neg = 0;
		if(1LL*(K+1)*X < N) {
			continue;
			// cost_neg += cost_pref[X];
			// for(int i = K*X; i < N-X; i += K) cost_neg += (S[min(N, i+X+K)] - S[i+X]) * (i/K);
		}
		else {
			int Y = (N-X)/K;
			cost_neg += cost_pref[Y];
			cost_neg += (S[N-(X-Y)] - S[(K+1)*Y]) * Y;
			cost_neg += SP[N]-SP[N-(X-Y)];
			cost_neg += (S[N]-S[N-(X-Y)]) * (-N+X);
		}

		// if((K+1)*X <= N) {
		// 	for(int i = 0; i < X; i++) for(int j = 0; j <= K; j++) cost_neg += A[i*(K+1)+j] * i;
		// 	for(int i = (K+1)*X, v = X; i < N; i += K, v++) for(int j = i; j < min(N, i+K); j++) cost_neg += A[j] * v;
		// }
		// else {
		// 	int Y = (N-X)/K;
		// 	for(int i = 0; i < Y; i++) for(int j = 0; j <= K; j++) cost_neg += A[i*(K+1)+j] * i;
		// 	for(int i = (K+1)*Y; i < (K+1)*Y+(N-X-K*Y); i++) cost_neg += A[i] * Y;
		// 	for(int i = (K+1)*Y+(N-X-K*Y), v = Y; i < N; i++, v++) cost_neg += A[i] * v;
		// }

		// int rneg = X, val_min = 0, n_min = K;
		// cat cost_neg0 = 0;
		// for(int i = 0; i < N; i++) {
		// 	if(rneg == N-i) {
		// 		cost_neg0 += (X-rneg) * A[i];
		// 		rneg--;
		// 		continue;
		// 	}
		// 	if(rneg && X-rneg == val_min) {
		// 		cost_neg0 += (X-rneg) * A[i];
		// 		rneg--;
		// 		continue;
		// 	}
		// 	cost_neg0 += val_min * A[i];
		// 	n_min--;
		// 	if(n_min == 0) {
		// 		n_min = K;
		// 		val_min++;
		// 	}
		// }
		// if(cost_neg0 != cost_neg) return -1;
		ans = max(ans, X * sum_pos + cost_pos + cost_neg);
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing