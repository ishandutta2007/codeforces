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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cat W;
		cin >> N >> W;
		vector< pair<cat, int> > A;
		cat sum = 0;
		for(int i = 0; i < N; i++) {
			cat a;
			cin >> a;
			if(a <= W) {
				A.push_back({a, i});
				sum += a;
			}
		}
		if(sum*2 < W) {
			cout << "-1\n";
			continue;
		}
		sort(begin(A), end(A));
		vector<int> ans;
		cat cur = 0;
		for(int i = (int)A.size()-1; i >= 0; i--) {
			if(cur+A[i].ff > W) continue;
			cur += A[i].ff;
			ans.push_back(A[i].ss);
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < (int)ans.size(); i++) {
			if(i > 0) cout << " ";
			cout << ans[i]+1;
		}
		cout << "\n";
	}
}

// look at my code
// my code is amazing