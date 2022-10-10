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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<int> pc(N+1, 0);
		for(int i = 1; i < N; i++) pc[i+1] = pc[i] + (i < N-1 && A[i] > A[i-1] && A[i] > A[i+1]);
		int pm = 0, ans = 0;
		for(int i = 0; i <= N-K; i++) if(pc[i+K-1]-pc[i+1] > pm) {
			pm = pc[i+K-1]-pc[i+1];
			ans = i;
		}
		cout << pm+1 << " " << ans+1 << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing