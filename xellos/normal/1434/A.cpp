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
	cat A[6];
	int N;
	cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4] >> A[5] >> N;
	sort(A, A+6);
	vector<cat> B(N);
	for(int i = 0; i < N; i++) cin >> B[i];
	sort(begin(B), end(B));
	cat ans_ge = OVER9000, ans_lt = -1;
	while(ans_ge-ans_lt > 1) {
		cat cur = (ans_lt+ans_ge)/2;
		bool ok = false;
		int L[6][6], R[6][6];
		for(int k = 0; k < 36; k++) L[k/6][k%6] = 0, R[k/6][k%6] = -1;
		for(int i = 0; i < N; i++) for(int k = 0; k < 6; k++) {
			// B[i]-A[k]+cur >= B[x]-A[y] >= B[i]-A[k]
			// B[i]-A[k]+cur+A[y] >= B[x] >= A[y]+B[i]-A[k]
			for(int l = 0; l < 6; l++) {
				while(L[k][l] < N && B[L[k][l]] < A[l]+B[i]-A[k]) L[k][l]++;
				while(R[k][l]+1 < N && B[R[k][l]+1] <= A[l]+B[i]-A[k]+cur) R[k][l]++;
			}
			int st = 0;
			for(int l = 0; l < 6; l++) if(L[k][l] <= st) st = R[k][l]+1;
			if(st == N) ok = true;
		}
		if(ok) ans_ge = cur;
		else ans_lt = cur;
	}
	cout << ans_ge << "\n";
}

// look at my code
// my code is amazing