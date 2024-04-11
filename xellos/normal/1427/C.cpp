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
	int L, N;
	cin >> L >> N;
	vector<int> cnt(N+1, -N), X(N+1, 0), Y(N+1, 0), T(N+1, 0);
	cnt[0] = 0;
	int m = -N;
	for(int i = 0; i < N; i++) {
		cin >> T[i+1] >> X[i+1] >> Y[i+1];
		X[i+1]--, Y[i+1]--;
		cnt[i+1] = m;
		for(int j = i; j >= max(0, i-2*L); j--) {
			int d = abs(X[i+1]-X[j]) + abs(Y[i+1]-Y[j]);
			if(d <= T[i+1]-T[j]) cnt[i+1] = max(cnt[i+1], cnt[j] + 1);
		}
		if(i+1 >= 2*L) m = max(m, cnt[i+1-2*L]+1);
	}
	for(int i = 0; i <= N; i++) m = max(m, cnt[i]);
	cout << m << "\n";
}

// look at my code
// my code is amazing