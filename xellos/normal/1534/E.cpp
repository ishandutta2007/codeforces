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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, K;
	cin >> N >> K;
	// vector<int> A(N);
	// for(int i = 0; i < N; i++) A[i] = rand()%1024;
	vector<int> D(N+1, 600);
	D[N] = 0;
	for(int i = 0; i < 600; i++) for(int j = 0; j <= N; j++) if(D[j] == i)
		for(int k = 0; k <= K; k++) if(k <= j && K-k <= N-j) // k times 1->0, K-k times 0->1
			D[j-k+K-k] = min(D[j-k+K-k], i+1);
	if(D[0] > 500) {
		cout << "-1" << endl;
		return 0;
	}
	vector<int> id1, id0(N);
	for(int i = 0; i < N; i++) id0[i] = i;
	int ans = 0;
	while(!id0.empty()) {
		int kf = 0;
		int n0 = id0.size(), n1 = id1.size();
		for(int k = 0; k <= K; k++) if(k <= n1 && K-k <= n0 && D[n1-k+K-k] == D[n1]-1) kf = k;
		vector<int> id1_nw, id0_nw;
		int x = 0;
		cout << "?";
		for(int k = 0; k < kf; k++) {
			// x ^= A[id1[k]];
			cout << " " << id1[k]+1;
			id0_nw.push_back(id1[k]);
		}
		for(int k = kf; k < n1; k++) id1_nw.push_back(id1[k]);
		for(int k = 0; k < K-kf; k++) {
			// x ^= A[id0[k]];
			cout << " " << id0[k]+1;
			id1_nw.push_back(id0[k]);
		}
		for(int k = K-kf; k < n0; k++) id0_nw.push_back(id0[k]);
		cout << endl;
		id1 = id1_nw, id0 = id0_nw;
		cin >> x;
		ans ^= x;
	}
	// int ans0 = 0;
	// for(int i = 0; i < N; i++) ans0 ^= A[i];
	// cout << ans0 << "\n";
	cout << "! " << ans << endl;
}

// look at my code
// my code is amazing