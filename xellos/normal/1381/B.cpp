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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> P(2*N), occ(2*N, 1);
		for(int i = 0; i < 2*N; i++) {
			cin >> P[i];
			P[i]--;
		}
		vector< vector<int> > seg;
		int r = 2*N-1, last = 2*N-1;
		while(true) {
			while(occ[last] == 0) last--;
			int l = r;
			while(P[l] != last) l--;
			seg.push_back({});
			for(int i = l; i <= r; i++) {
				occ[P[i]]--;
				seg.back().push_back(P[i]);
			}
			if(l == 0) break;
			r = l-1;
		}
		vector<int> dp(N+1, 0);
		dp[0] = 1;
		for(int i = 0; i < (int)seg.size(); i++) {
			int L = seg[i].size();
			if(L > N) break;
			for(int j = N-L; j >= 0; j--) dp[j+L] |= dp[j];
		}
		cout << (dp[N] ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing