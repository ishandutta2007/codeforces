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
	int N, K;
	cin >> N >> K;
	vector< vector<cat> > A(1<<12);
	vector<int> L(1<<12, 0);
	vector<cat> S(1<<12, 0);
	for(int i = 0; i < N; i++) {
		cin >> L[i];
		A[i].resize(L[i]);
		for(int j = 0; j < L[i]; j++) {
			cin >> A[i][j];
			S[i] += A[i][j];
		}
	}
	vector< vector<cat> > dp(1, vector<cat>(K+1, 0));
	for(int k = 11; k >= 0; k--) {
		vector< vector<cat> > dp_nw(1<<(12-k), vector<cat>(K+1, 0));
		for(int i = 0; i < (1<<(12-k)); i++) {
			vector<cat> dp_tmp = dp[i/2];
			int l = (1<<(k+1)) * (i/2), r = (1<<(k+1)) * (i/2+1);
			if(i&1) r = (l+r)/2;
			else l = (l+r)/2;
			for(int j = l; j < r; j++)
				for(int sj = K-L[j]; sj >= 0; sj--)
					dp_tmp[sj+L[j]] = max(dp_tmp[sj+L[j]], dp_tmp[sj]+S[j]);
			dp_nw[i] = dp_tmp;
		}
		dp = dp_nw;
	}
	cat ans = 0;
	for(int i = 0; i < N; i++) {
		cat s = 0;
		for(int j = 0; j <= min(K, L[i]); j++) {
			if(j) s += A[i][j-1];
			ans = max(ans, s + dp[i][K-j]);
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing