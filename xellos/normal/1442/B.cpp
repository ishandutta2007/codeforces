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
		int N, K;
		cin >> N >> K;
		vector<int> A(N), pos(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			pos[--A[i]] = i;
		}
		vector<int> B(K);
		for(int i = 0; i < K; i++) {
			cin >> B[i];
			B[i]--;
		}
		cat mod = 998244353, ans = 1;
		set<int> used;
		used.insert(-1);
		used.insert(N);
		for(int i = K-1; i >= 0; i--) {
			int p = pos[B[i]];
			auto it_r = used.upper_bound(p);
			auto it_l = used.lower_bound(p);
			it_l--;
			int cnt = 0;
			if(*it_l < p-1) cnt++;
			if(*it_r > p+1) cnt++;
			ans = ans * cnt % mod;
			used.insert(p);
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing