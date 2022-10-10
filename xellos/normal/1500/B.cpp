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

void find_ans(vector<int> A, int a, int b, int c, int d) {
	int N = A.size();
	int bl[4] = {-1, -1, -1, -1};
	for(int i = 0; i < N; i++) if(A[i] == a) {
		bl[0] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == b && i != bl[0]) {
		bl[1] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == c && i != bl[0] && i != bl[1]) {
		bl[2] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == d && i != bl[0] && i != bl[1] && i != bl[2]) {
		bl[3] = i;
		break;
	}
	cout << "YES\n" << bl[0]+1 << " " << bl[1]+1 << " " << bl[2]+1 << " " << bl[3]+1 << "\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cat K;
	cin >> N >> M >> K;
	vector<int> A(N), B(M);
	vector<int> DA(2*N+2*M+1, -1), DB(2*N+2*M+1, -1);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		DA[A[i]] = i;
	}
	for(int i = 0; i < M; i++) {
		cin >> B[i];
		DB[B[i]] = i;
	}
	int G = gcd(N, M);
	vector< pair<int, int> > C;
	for(int i = 0; i < N; i++) if(DB[A[i]] != -1 && (DB[A[i]]-i)%G == 0)
		C.push_back({i, DB[A[i]]});
	int n = N/G, m = M/G;
	vector<int> inv(n);
	for(int i = 0; i < n; i++) inv[(1LL*i*m)%n] = i;
	cat D_lt = -1, D_ge = 1000000000000000000;
	while(D_ge-D_lt > 1) {
		cat D = (D_ge + D_lt) / 2;
		cat D_eq = 0;
		for(auto [a,b] : C) {
			int g = a%G;
			// (a-g)/G+k(N/G) == (b-g)/G+l(M/G) <= (D-g)/G
			if(g > D) continue;
			cat d = (D-g)/G;
			// min. (k,l): a/G+kn == b/G+lm <= d; (n,m) = 1
			// k+m, l+n, day + mn
			cat l = (a/G-b/G)%n;
			if(l < 0) l += n;
			l = inv[l];
			if(l*m+b/G < a/G) l += n;
			// cat k = (l*m+b/G-a/G)/n;
			cat d_min = l*m+b/G;
			if(d_min > d) continue;
			D_eq += (d-d_min)/(1LL*n*m)+1;
		}
		if(D+1 - D_eq >= K) D_ge = D;
		else D_lt = D;
	}
	cout << D_ge+1 << "\n";
}

// look at my code
// my code is amazing