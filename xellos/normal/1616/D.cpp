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
#define OVER9000 1234567890123456789LL
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
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		int X;
		cin >> X;
		vector<char> ok2(N, 0), ok3(N, 0);
		for(int i = 1; i < N; i++) ok2[i-1] = (A[i-1]+A[i] >= 2*X);
		for(int i = 2; i < N; i++) ok3[i-2] = (A[i-2]+A[i-1]+A[i] >= 3*X);
		vector<int> dp(N+1);
		dp[0] = 0;
		int lastf2 = -1, lastf3 = -1;
		vector< pair<int,int> > V;
		for(int i = 0; i < N; i++) {
			dp[i+1] = dp[i];
			if(i-1 >= 0 && ok2[i-1] == 0) lastf2 = i-1;
			if(i-2 >= 0 && ok3[i-2] == 0) lastf3 = i-2;
			int l = max(lastf2, lastf3) + 1;
			if(l == 0) dp[i+1] = max(dp[i+1], i+1);
			l = max(0, l-1);
			if(l >= i) continue;
			int bl = -1, br = V.size();
			while(br-bl > 1) {
				int bm = (bl+br)/2;
				if(V[bm].ss >= l) br = bm;
				else bl = bm;
			}
			if(br < (int)V.size()) dp[i+1] = max(dp[i+1], V[br].ff+i);
			while(!V.empty() && V.back().ff <= dp[i]-i) V.pop_back();
			V.push_back({dp[i]-i, i});
		}
		cout << dp[N] << "\n";
	}
}

// look at my code
// my code is amazing