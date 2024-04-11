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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int BAND[3][3], BOR[3][3];
	for(int i = 0; i < 3; i++) for(int j = 0; j < i; j++) {
		cout << "or " << i+1 << " " << j+1 << endl;
		cin >> BOR[i][j];
		BOR[j][i] = BOR[i][j];
		cout << "and " << i+1 << " " << j+1 << endl;
		cin >> BAND[i][j];
		BAND[j][i] = BAND[i][j];
	}
	A[0] = 0;
	for(int k = 0; k < 30; k++) {
		if(((BAND[0][1]|BAND[0][2])>>k)&1) A[0] |= 1<<k;
		else if(((BOR[0][1]&BOR[0][2])>>k)&1)
			if(((BOR[1][2]>>k)&1) == 0) A[0] |= 1<<k;
	}
	for(int k = 1; k <= 2; k++) A[k] = (BOR[0][k]^BAND[0][k])^A[0];
	for(int k = 3; k < N; k++) {
		A[k] = A[0];
		int a;
		cout << "or 1 " << k+1 << endl;
		cin >> a;
		A[k] ^= a;
		cout << "and 1 " << k+1 << endl;
		cin >> a;
		A[k] ^= a;
	}
	sort(begin(A), end(A));
	cout << "finish " << A[K-1] << endl;
}

// look at my code
// my code is amazing