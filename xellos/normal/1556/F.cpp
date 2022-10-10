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
	cat mod = 1000000007;
	int N;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int P[14][14];
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		P[i][j] = A[i] * pw(A[i]+A[j], mod-2, mod) % mod;
	vector< vector<cat> > P_sub(N, vector<cat>(1<<N,1));
	for(int i = 0; i < N; i++) for(int j = 1; j < (1<<N); j++) if(((j>>i)&1) == 0)
		for(int k = 0; k < N; k++) if((j>>k)&1) P_sub[i][j] = P_sub[i][j] * P[i][k] % mod;
	vector<cat> P_scc(1<<N, 1);
	for(int i = 1; i < (1<<N); i++) {
		vector<int> fr;
		for(int j = 0; j < N; j++) if(((i>>j)&1) == 0) fr.push_back(j);
		int B = fr.size();
		static int bm[1<<15];
		static cat coef[1<<15];
		bm[0] = 0;
		coef[0] = 1;
		for(int j = 0, b = 0; j < (1<<B); j++) {
			while((1<<b) <= j) b++;
			for(int k = b; k < B; k++) {
				bm[j|(1<<k)] = bm[j] | (1<<fr[k]);
				coef[j|(1<<k)] = coef[j] * P_sub[fr[k]][i] % mod;
			}
		}
		for(int j = 1; j < (1<<B); j++) {
			P_scc[i|bm[j]] = (P_scc[i|bm[j]] - P_scc[i] * coef[j]) % mod;
		}
	}
	cat ans = 0;
	for(int i = 1; i < (1<<N); i++) {
		cat p = P_scc[i];
		int cnt = 0;
		for(int j = 0; j < N; j++) if((i>>j)&1) {
			cnt++;
			for(int k = 0; k < N; k++) if(((i>>k)&1) == 0)
				p = p * P[j][k] % mod;
		}
		ans = (ans + p * cnt) % mod;
	}
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing