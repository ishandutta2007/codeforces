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
		vector<cat> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		if(N == 1) {
			cout << "1\n";
			continue;
		}
		vector<cat> G[20];
		for(int k = 0; k < 20; k++) G[k].resize(N-1, 1);
		for(int i = 1; i < N; i++) G[0][i-1] = abs(A[i]-A[i-1]);
		for(int k = 1; k < 20; k++)
			for(int i = 0; i <= N-1-(1<<k); i++)
				G[k][i] = gcd(G[k-1][i], G[k-1][i+(1<<(k-1))]);
		int ans = 0;
		for(int i = 0; i < N-1; i++) if(G[0][i] > 1) {
			cat g = G[0][i];
			int r = i+1; // gcd [i,r)
			for(int k = 19; k >= 0; k--) {
				// * gcd [r,r+(1<<k))
				if(r+(1<<k) > N-1) continue;
				cat g_nw = gcd(g, G[k][r]);
				if(g_nw > 1) {
					r += 1<<k;
					g = g_nw;
				}
			}
			ans = max(ans, r-i);
		}
		cout << ans+1 << "\n";
	}
}

// look at my code
// my code is amazing