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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cat mod;
	cin >> N >> M >> mod;
	vector<cat> fac(N+1, 1), inv(N+1, 1);
	for(int i = 1; i <= N; i++) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = inv[i-1] * pw(i, mod-2, mod) % mod;
	}
	vector<cat> cnt(M+1, 0);
	vector<cat> sum(M+1, 0);
	cnt[0] = 1;
	for(int m = 1; m <= M; m++) {
		for(int k = 0; k < m; k++) {
			cat cl = cnt[k] * inv[k] % mod, cr = cnt[m-1-k] * inv[m-1-k] % mod;
			cat sl = sum[k] * inv[k] % mod, sr = sum[m-1-k] * inv[m-1-k] % mod;
			cnt[m] += cl * cr % mod * (m+1);
			sum[m] += (cl * sr + sl * cr) % mod * (m+1);
			sum[m] += cl * cr % mod * (k*(k+1)+(m-k)*(m-k-1))/2 % mod;
		}
		cnt[m] = cnt[m] % mod * fac[m-1] % mod;
		sum[m] = sum[m] % mod * fac[m-1] % mod;
	}
	vector< vector<cat> > cnt_ans(N+1, vector<cat>(M+1, 0));
	vector< vector<cat> > sum_ans(N+1, vector<cat>(M+1, 0));
	cnt_ans[0][0] = 1;
	for(int i = 1; i <= N; i++) {
		cnt_ans[i] = cnt_ans[i-1];
		sum_ans[i] = sum_ans[i-1];
		if(i <= M) {
			cnt_ans[i][i] = cnt[i] * inv[i] % mod;
			sum_ans[i][i] = sum[i] * inv[i] % mod;
		}
		for(int j = 0; j <= min(i-1, M); j++) for(int k = 1; k <= j; k++) {
			cat c = cnt[k] * inv[k] % mod;
			cat s = sum[k] * inv[k] % mod;
			cnt_ans[i][j] = (cnt_ans[i][j] + cnt_ans[i-1-k][j-k] * c) % mod;
			sum_ans[i][j] = (sum_ans[i][j] + sum_ans[i-1-k][j-k] * c + cnt_ans[i-1-k][j-k] * s) % mod;
		}
	}
	cat ans = sum_ans[N][M] * fac[M] % mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing