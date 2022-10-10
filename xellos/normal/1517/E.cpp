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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<cat> S(N+1, 0), S2(N+1, 0);
		for(int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
		for(int i = 0; i < N; i++) S2[i+1] = ((i < 2) ? 0 : S2[i-1]) + A[i];
		cat ans = 0;
		if(S2[N] > S2[N-1]) ans++;
		if(S2[N] < S2[N-1]) ans++;
		if(N == 1) {
			cout << ans << "\n";
			continue;
		}
		for(int i = 1; i < N-2; i++) if(S[i+1] > S[N]-S[i+1]) ans++;
		for(int sl = 0; sl < 2; sl++) for(int sr = N-1; sr <= N; sr++) {
			for(int i = sl+1; i < sr; i++) if((sr-i)&1) {
				cat P = (sl ? A[0] : 0) + ((sr == N) ? 0 : A[N-1]) + S2[sr-1] - S2[i];
				cat C = S[i+1] - S[sl] + S2[sr] - S2[i+1];
				if(P > C) ans++;
			}
			for(int i = sr-2; i >= sl; i--) if((i-sl+1)&1) {
				cat P = S[sr]-S[i] + ((i == 0) ? 0 : S2[i-1]) - ((sl == 0) ? 0 : S2[sl-1]);
				cat C = (sl ? A[0] : 0) + ((sr == N) ? 0 : A[N-1]) + S2[i] - S2[sl];
				if(P > C) ans++;
			}
			// for(int i = sl+1; i < sr-2; i++) for(int j = i+1; j <= sr-2; j += 2) {
			// 	cat P = (sl ? A[0] : 0) + S[sr]-S[j] + S2[j-1]-S2[i];
			// 	cat C = ((sr == N) ? 0 : A[N-1]) + S[i+1]-S[sl] + S2[j]-S2[i+1];
			// 	if(P > C) ans++;
			// }
			for(int i = sl+1; i < sr-2; i++) {
				cat P = (sl ? A[0] : 0) + S[sr] - S2[i];
				cat C = ((sr == N) ? 0 : A[N-1]) + S[i+1] - S[sl] - S2[i+1];
				cat D = (P-C-1)/2;
				if(P <= C || S2[i+1] > D) continue;
				int j = i+1;
				for(int k = 19; k >= 1; k--) if(j+(1<<k) <= sr-2 && S2[j+(1<<k)] <= D) j += (1<<k);
				ans += (j-i+1)/2;
			}
		}
		cout << ans%998244353 << "\n";
	}
}

// look at my code
// my code is amazing