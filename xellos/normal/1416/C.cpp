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
#define OVER9000 1234567890123LL
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

struct fin {
	vector<cat> T;
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {return x & (x ^ (x-1));}

	void put(int pos) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i]++;
	}
	
	cat get(int pos) {
		cat ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

cat count_inv(vector<cat> & A) {
	int N = A.size();
	static vector<cat> V(N);
	for(int i = 0; i < N; i++) V[i] = (A[i]<<20)+i;
	sort(begin(V), end(V));
	static vector<int> B(N);
	for(int i = 0, cur = 0; i < N; i++) {
		if(i > 0 && (V[i]>>20) != (V[i-1]>>20)) cur++;
		B[V[i]-((V[i]>>20)<<20)] = cur;
	}
	fin F(N);
	cat n_inv = 0;
	for(int i = N-1; i >= 0; i--) {
		F.put(B[i]+1);
		n_inv += F.get(B[i]);
	}
	return n_inv;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cat inv_cur = count_inv(A);
	cat X = 0;
	for(int b = 29; b >= 0; b--) {
		vector<cat> Ax(N);
		for(int i = 0; i < N; i++) Ax[i] = A[i] ^ (1<<b);
		cat inv_nw = count_inv(Ax);
		if(inv_nw < inv_cur) {
			inv_cur = inv_nw;
			A = Ax;
			X ^= 1<<b;
		}
	}
	cout << inv_cur << " " << X << "\n";
}

// look at my code
// my code is amazing