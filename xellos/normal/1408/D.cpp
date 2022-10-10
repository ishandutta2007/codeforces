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
	int N, M;
	cin >> N >> M;
	vector< pair<int, int> > R(N), S(M);
	for(int i = 0; i < N; i++) cin >> R[i].ff >> R[i].ss;
	for(int i = 0; i < M; i++) cin >> S[i].ff >> S[i].ss;
	vector<int> max_d(1000010, -1);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(R[i].ff > S[j].ff) continue;
		if(R[i].ss > S[j].ss) continue;
		max_d[S[j].ff-R[i].ff] = max(max_d[S[j].ff-R[i].ff], S[j].ss-R[i].ss);
	}
	// dx <= i? then dy > max_d[i]
	int m = -1, ans = 20000000;
	for(int i = 1000001; i >= 0; i--) {
		m = max(m, max_d[i]);
		ans = min(ans, i+m+1);
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing