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
	int N;
	cin >> N;
	if(N <= 2) {
		cout << "0\n";
		return 0;
	}
	vector<cat> A(N);
	for(int i = 0; i < N; i++)
		// A[i] = rand()%100000+1;
		cin >> A[i];
	int ans = 2;
	constexpr int K = 350, MX = 100000;
	vector<int> cnt(MX*K, 0);
	for(int r = 0; r < 2; r++) {
		for(int k = 0; k <= K-5; k++) {
			for(int i = 0; i < N; i++) ans = max(ans, ++cnt[A[i]-k*i+k*MX]);
			for(int i = 0; i < N; i++) cnt[A[i]-k*i+k*MX] = 0;
		}
		for(int i = 0; i <= MX; i++) cnt[i] = 1;
		for(int i = 0; i < N; i++) {
			for(int j = i+1; j < min(N, i+K); j++) if(A[j] > A[i] && (A[j]-A[i])%(j-i) == 0)
				ans = max(ans, ++cnt[(A[j]-A[i])/(j-i)]);
			for(int j = i+1; j < min(N, i+K); j++) if(A[j] > A[i] && (A[j]-A[i])%(j-i) == 0)
				cnt[(A[j]-A[i])/(j-i)] = 1;
		}
		for(int i = 0; i <= MX; i++) cnt[i] = 0;
		reverse(begin(A), end(A));
	}
	cout << N-ans << "\n";
}

// look at my code
// my code is amazing