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
	cin >> N >> M;
	vector<cat> fac(N+1, 1);
	cat mod = 998244353;
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % mod;
	vector<cat> inv(N+5, 1);
	inv[2] = pw(2, mod-2, mod);
	inv[3] = pw(3, mod-2, mod);
	for(int i = 4; i <= N; i++) {
		if(i%2 == 0) inv[i] = inv[2] * inv[i/2] % mod;
		else if(i%3 == 0) inv[i] = inv[3] * inv[i/3] % mod;
		else inv[i] = pw(i, mod-2, mod);
	}
	vector<cat> inv_fac(N+1, 1);
	for(int i = 1; i <= N; i++) inv_fac[i] = inv_fac[i-1] * inv[i] % mod;
	cat E_n_steps = 0;
	for(int i = 1; i <= N; i++) E_n_steps += (2*(i%2)-1) * inv[i] * inv_fac[i] % mod * inv_fac[N-i] % mod;
	E_n_steps = (E_n_steps % mod * M % mod * fac[N] + 1) % mod;
	cat E = E_n_steps * (M+N+1) % mod * pw(M+1, mod-2, mod) % mod;
	if(E < 0) E += mod;
	cout << E << "\n";
}

// look at my code
// my code is amazing