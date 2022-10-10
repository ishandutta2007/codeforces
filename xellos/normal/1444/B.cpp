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
#define OVER9000 1234567890123LL
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
	int N;
	cin >> N;
	vector<int> A(2*N);
	for(int i = 0; i < 2*N; i++) cin >> A[i];
	sort(begin(A), end(A));
	cat ans = 0, mod = 998244353;
	for(int i = 0; i < N; i++) ans -= A[i];
	for(int i = 0; i < N; i++) ans += A[i+N];
	ans %= mod;
	for(int i = 1; i < 2*N; i += 2) ans = ans * i % mod;
	for(int i = 1; i <= N; i++) ans = ans * 2 * pw(i, mod-2, mod) % mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing