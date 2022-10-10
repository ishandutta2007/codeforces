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
	int T;
	cin >> T;
	while(T--) {
		int N, L;
		cin >> N >> L;
		vector<int> A(N+2, 0);
		A[N+1] = L;
		for(int i = 0; i < N; i++) cin >> A[i+1];
		vector<double> tm[2];
		tm[0].resize(N+2, 0);
		for(int i = 1; i <= N+1; i++) tm[0][i] = tm[0][i-1] + 1.*(A[i]-A[i-1])/i;
		tm[1].resize(N+2, 0);
		for(int i = N; i >= 0; i--) tm[1][i] = tm[1][i+1] + 1.*(A[i+1]-A[i])/(N+1-i);
		double ans = 0;
		for(int i = 0; i <= N; i++) {
			double tl = max(tm[0][i], tm[1][i+1]);
			double tr = min(tm[0][i+1], tm[1][i]);
			if(tl > tr+soclose) continue;
			// x == (i+1)*(t-tm[0][i])
			// A[i+1]-x == (N+1-i)*(t-tm[1][i+1])
			// A[i+1]+(i+1)*tm[0][i]+(N+1-i)*tm[1][i+1] == (N+2)*t
			ans = (A[i+1]-A[i]+(i+1)*tm[0][i]+(N+1-i)*tm[1][i+1]) / (N+2);
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing