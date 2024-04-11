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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(M);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];
	int ans = 0;
	for(int b = 10; b >= 0; b--) {
		for(int i = 0; i < N; i++) if((A[i]>>b)&1) {
			bool has0 = false;
			for(int j = 0; j < M; j++)
				has0 |= (((ans|(A[i]&B[j]))>>(b+1)) <= (ans>>(b+1))) && (((B[j]>>b)&1) == 0);
			if(!has0) {
				ans |= 1<<b;
				break;
			}
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing