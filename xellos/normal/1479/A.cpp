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
	vector<int> A(N, 0);
	if(N <= 4) {
		for(int i = 0; i < N; i++) {
			cout << "? " << i+1 << endl;
			cin >> A[i];
		}
		for(int i = 0; i < N; i++) if(A[i] == 1) {
			cout << "! " << i+1 << endl;
			return 0;
		}
	}
	cout << "? 1" << endl;
	cin >> A[0];
	cout << "? 2" << endl;
	cin >> A[1];
	if(A[1] > A[0]) {
		cout << "! 1" << endl;
		return 0;
	}
	cout << "? " << N << endl;
	cin >> A[N-1];
	cout << "? " << N-1 << endl;
	cin >> A[N-2];
	if(A[N-2] > A[N-1]) {
		cout << "! " << N << endl;
		return 0;
	}
	int l = 0, r = N-1, m = 1;
	if(A[N-2] < A[1]) m = N-2;
	while(true) {
		if(l < m-1 && m-l >= r-m) {
			int ml = (l+m)/2;
			cout << "? " << ml+1 << endl;
			cin >> A[ml];
			if(A[ml] < A[m]) {
				r = m;
				m = ml;
			}
			else {
				l = ml;
			}
			continue;
		}
		if(r > m+1) {
			int mr = (r+m)/2;
			cout << "? " << mr+1 << endl;
			cin >> A[mr];
			if(A[mr] < A[m]) {
				l = m;
				m = mr;
			}
			else {
				r = mr;
			}
			continue;
		}
		break;
	}
	cout << "! " << m+1 << endl;
}

// look at my code
// my code is amazing