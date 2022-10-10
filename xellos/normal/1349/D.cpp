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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

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
	int N;
	cin >> N;
	vector<int> A(N);
	int S = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		S += A[i];
	}
	if(S == 1) {
		cout << "0\n";
		return 0;
	}
	cat mod = 998244353;
	vector<int> inv(S+1, 1), P(S+1, 1);
	for(int i = 1; i*i <= S; i++)
		for(int j = 2*i; j <= S; j += i) P[j] = i;
	for(int i = 1; i <= S; i++) {
		if(P[i] > 1) inv[i] = 1LL * inv[i/P[i]] * inv[P[i]] % mod;
		else inv[i] = pw(i, mod-2, mod);
	}
	cat iN = pw(N-1, mod-2, mod);
	vector<cat> E(S+1, 0), E_lf_c(S+1, 0), E_lf_a(S+1, 0);
	E_lf_a[1] = 1;
	// E[0] = 0
	// E[i] = 1 + (1-i/S) E[i+1] + i/S 1/(N-1) E[i-1] + i/S (1-1/(N-1)) E[i]
	for(int i = 1; i < S; i++) {
		cat c1 = i * iN % mod;
		cat c2 = S - i + c1;
		E_lf_a[i+1] = (c2 * E_lf_a[i] - c1 * E_lf_a[i-1]) % mod * inv[S-i] % mod;
		E_lf_c[i+1] = (c2 * E_lf_c[i] - c1 * E_lf_c[i-1] - S) % mod * inv[S-i] % mod;
	}
	// E[S] == N-1 + E[S-1]
	E[1] = (N-1 + E_lf_c[S-1] - E_lf_c[S]) * pw(E_lf_a[S]-E_lf_a[S-1], mod-2, mod) % mod;
	for(int i = 2; i <= S; i++) E[i] = (E[1] * E_lf_a[i] + E_lf_c[i]) % mod;
	cat E_cyc = E[S];
	cat ans = 0;
	for(int i = 0; i < N; i++) ans += E[S-A[i]];
	ans = (ans - (N-1) * E_cyc) % mod * pw(N, mod-2, mod) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing