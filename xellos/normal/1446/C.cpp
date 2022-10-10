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

int solve(auto & A, int L, int R, int B) {
	// A[L..R)
	if(B < 0) return 1;
	if((A[L]>>B)&1) return solve(A, L, R, B-1);
	if(!((A[R-1]>>B)&1)) return solve(A, L, R, B-1);
	int l = L, r = R-1; // A[l] < 2^B, A[r] >= 2^B
	while(!((A[l+1]>>B)&1) || ((A[r-1]>>B)&1)) {
		if(!((A[l+1]>>B)&1)) l++;
		if(((A[r-1]>>B)&1)) r--;
	}
	if((A[l+1]>>B)&1) r = l+1;
	else l = r-1;
	int cnt_l = solve(A, L, r, B-1);
	int cnt_r = solve(A, r, R, B-1);
	return 1 + max(cnt_l, cnt_r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(begin(A), end(A));
	cout << N - solve(A, 0, N, 29) << "\n";
}

// look at my code
// my code is amazing