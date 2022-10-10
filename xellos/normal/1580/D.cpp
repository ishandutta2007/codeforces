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

vector<cat> solve(vector<cat> & A, int M) {
	int N = A.size();
	if(N == 0) return {0};
	int mi = 0;
	for(int i = 1; i < N; i++) if(A[i] < A[mi]) mi = i;
	vector<cat> Al(mi), Ar(N-1-mi);
	for(int i = 0; i < mi; i++) Al[i] = A[i];
	for(int i = mi+1; i < N; i++) Ar[i-mi-1] = A[i];
	vector<cat> Vl = solve(Al, M), Vr = solve(Ar, M);
	int Sl = min(M, (int)Al.size()), Sr = min(M, (int)Ar.size());
	vector<cat> ret(min(M,N)+1, 0);
	for(int i = 0; i <= Sl; i++) for(int j = 0; j <= min(Sr, M-i); j++)
		ret[i+j] = max(ret[i+j], Vl[i] + Vr[j] - A[mi] * 2*i*j);
	for(int i = 0; i <= Sl; i++) for(int j = 0; j <= min(Sr, M-1-i); j++)
		ret[i+j+1] = max(ret[i+j+1], Vl[i] + Vr[j] + A[mi] * (M-1-2*i*j-2*i-2*j));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M;
	cin >> N >> M;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<cat> V = solve(A, M);
	cout << V[M] << "\n";
}

// look at my code
// my code is amazing