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
	fin() = default;

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

constexpr cat MOD = 998244353;

cat pw2[200000];

cat solve2(vector<int> & A, vector<int> & B, int X, int b) {
	int N = A.size(), M = B.size();
	if(N == 0 || M == 0) return 0;
	if(b == -1) return (pw2[N]-1) * (pw2[M]-1) % MOD;
	vector<int> As[2];
	for(int i = 0; i < N; i++) As[A[i]>>b].push_back(A[i]-((A[i]>>b)<<b));
	vector<int> Bs[2];
	for(int i = 0; i < M; i++) Bs[B[i]>>b].push_back(B[i]-((B[i]>>b)<<b));
	if((X>>b) == 0) {
		cat ret = solve2(As[0], Bs[0], X, b-1) + solve2(As[1], Bs[1], X, b-1);
		if(ret >= MOD) ret -= MOD;
		return ret;
	}
	else {
		cat r[2] = {solve2(As[1], Bs[0], X-(1<<b), b-1), solve2(As[0], Bs[1], X-(1<<b), b-1)};
		cat p[2][2] = {{pw2[As[0].size()], pw2[As[1].size()]}, {pw2[Bs[0].size()], pw2[Bs[1].size()]}};
		cat ret = r[0] * (p[0][0]+p[1][1]-1) + r[1] * (p[0][1]+p[1][0]-1) + (p[0][0]-1) * (p[1][0]-1) + (p[0][1]-1) * (p[1][1]-1) + r[0] * r[1];
		ret %= MOD;
		return ret;
	}
	cat ret = 0;
	for(int i = 1; i < (1<<A.size()); i++) {
		int a = 0;
		for(int j = 0; j < (int)B.size(); j++) {
			int c = 0;
			for(int k = 0; k < (int)A.size(); k++) if((i>>k)&1) c += ((A[k]^B[j]) > X);
			if(c == 0) a++;
		}
		ret += pw2[a]-1;
		if(ret >= MOD) ret -= MOD;
	}
	return ret;
}

cat solve1(vector<int> & A, int X, int b = 30) {
	int N = A.size();
	if(N == 0) return 0;
	vector<int> B[2];
	for(int i = 0; i < N; i++) B[A[i]>>b].push_back(A[i]-((A[i]>>b)<<b));
	if((X>>b) == 0) {
		cat ret = solve1(B[0], X, b-1) + solve1(B[1], X, b-1);
		if(ret >= MOD) ret -= MOD;
		return ret;
	}
	cat ret = solve2(B[0], B[1], X-(1<<b), b-1) + pw2[B[0].size()]-1 + pw2[B[1].size()]-1;
	if(ret >= MOD) ret -= MOD;
	if(ret >= MOD) ret -= MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	pw2[0] = 1;
	for(int i = 1; i <= N; i++) {
		pw2[i] = 2*pw2[i-1];
		if(pw2[i] >= MOD) pw2[i] -= MOD;
	}
	if(X == 0) {
		int ans = 0;
		sort(begin(A), end(A));
		for(int i = 0; i < N; i++) if(i == 0 || A[i-1] != A[i]) {
			int j = i;
			while(j < N && A[j] == A[i]) j++;
			ans += pw2[j-i]-1;
			if(ans >= MOD) ans -= MOD;
		}
		cout << ans << "\n";
		return 0;
	}
	cout << solve1(A, X) << "\n";
}

// look at my code
// my code is amazing