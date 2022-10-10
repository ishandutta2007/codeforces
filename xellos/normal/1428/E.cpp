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

cat cost(cat a, int n) {
	return (a%n) * (a/n+1) * (a/n+1) + (n-a%n) * (a/n) * (a/n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector<cat> A(N);
	cat ans = 0;
	priority_queue< pair<cat, int> > q;
	vector<int> cur(N, 1);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		q.push({cost(A[i], cur[i]) - cost(A[i], cur[i]+1), i});
		ans += 1LL*A[i]*A[i];
	}
	for(int i = 0; i < K-N; i++) {
		auto p = q.top();
		q.pop();
		ans -= p.ff;
		cur[p.ss]++;
		q.push({cost(A[p.ss], cur[p.ss]) - cost(A[p.ss], cur[p.ss]+1), p.ss});
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing