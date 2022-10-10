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
		string S;
		cin >> S;
		int nL = 0;
		for(int i = 0; i < N; i++) if(S[i] == 'L') nL++;
		if(nL <= K) {
			cout << 2*N-1 << "\n";
			continue;
		}
		if(nL == N) {
			cout << ((K == 0) ? 0 : (2*K-1)) << "\n";
			continue;
		}
		vector<int> lL;
		for(int i = 1; i < N; i++) if(S[i] == 'L' && S[i-1] == 'W') {
			int j = i;
			while(j < N && S[j] == 'L') j++;
			if(j < N) lL.push_back(j-i);
		}
		int ans = 2*(N-nL+K)-(lL.size()+1);
		sort(begin(lL), end(lL));
		for(int i = 0; i < (int)lL.size(); i++) if(lL[i] <= K) {
			K -= lL[i];
			ans++;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing