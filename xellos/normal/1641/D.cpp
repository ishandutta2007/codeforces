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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

int solve(auto & A, auto & B, int & ans) {
	int nA = A.size(), nB = B.size(), mA = (int)A[0].size()-1, mB = (int)B[0].size()-1;
	vector< vector<int> > grB[1<<5];
	for(int i = 0; i < nB; i++) {
		int occ = 0;
		vector<int> v = {B[i][0]};
		for(int k = 1; k <= mB; k++) {
			bool found = false;
			for(int j = 1; j <= mA; j++) occ |= (int(B[i][k] == A[0][j])) << (j-1), found |= (B[i][k] == A[0][j]);
			if(!found) v.push_back(B[i][k]);
		}
		if(occ == 0) {
			ans = min(ans, A[0][0] + B[i][0]);
			break;
		}
		grB[occ].push_back(v);
	}
	vector< vector<int> > grA[1<<5];
	for(int i = 0; i < nA; i++) {
		int occ = 0;
		vector<int> v = {A[i][0]};
		for(int k = 1; k <= mA; k++) {
			bool found = false;
			for(int j = 1; j <= mA; j++) occ |= (int(A[i][k] == A[0][j])) << (j-1), found |= (A[i][k] == A[0][j]);
			if(!found) v.push_back(A[i][k]);
		}
		grA[occ].push_back(v);
	}
	for(int i = 0; i < (1<<mA); i++) for(int j = 1; j < (1<<mA); j++) if((i&j) == 0 && !grA[i].empty() && !grB[j].empty())
		solve(grA[i], grB[j], ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > A(N, vector<int>(M+1));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> A[i][j+1];
		}
		cin >> A[i][0];
	}
	sort(begin(A), end(A));
	int ans = A[N-1][0]*2+1;
	solve(A, A, ans);
	if(ans == A[N-1][0]*2+1) ans = -1;
	cout << ans << "\n";
}

// look at my code
// my code is amazing