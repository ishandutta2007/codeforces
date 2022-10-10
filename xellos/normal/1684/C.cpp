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
	int T;
	cin >> T;
	while(T--) {
		int N,M;
		cin >> N >> M;
		vector< vector<int> > A(N, vector<int>(M));
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> A[i][j];
		vector<char> bad(M-1, 0);
		for(int i = 0; i < N; i++) for(int j = 1; j < M; j++) if(A[i][j] < A[i][j-1]) bad[j-1] = 1;
		int l_bad = -1, r_bad = -1;
		for(int i = 0; i < M-1; i++) if(bad[i]) {
			if(l_bad == -1) l_bad = i;
			r_bad = i;
		}
		if(l_bad == -1) {
			cout << "1 1\n";
			continue;
		}
		if(l_bad+1 < r_bad) {
			int ans = -1;
			for(int l = l_bad; l <= l_bad+1; l++) for(int r = r_bad; r <= r_bad+1; r++) {
				if(ans != -1) break;
				for(int i = 0; i < N; i++) swap(A[i][l], A[i][r]);
				bool ok = true;
				for(int i = 0; i < N; i++) for(int j = 1; j < M; j++) if(A[i][j] < A[i][j-1]) ok = false;
				if(ok) {
					ans = 0;
					cout << l+1 << " " << r+1 << "\n";
				}
				for(int i = 0; i < N; i++) swap(A[i][l], A[i][r]);
			}
			if(ans == -1) cout << "-1\n";
			continue;
		}
		int cost = 0;
		for(int i = 0; i < N; i++) for(int j = 1; j < M; j++) if(A[i][j] < A[i][j-1]) cost++;
		pair<int,int> ans = {-1,-1};
		for(int l = l_bad; l <= l_bad+1; l++) for(int c = 0; c < M; c++) if(c != l) {
			set<int> dif;
			if(l-1 >= 0) dif.insert(l-1);
			if(l+1 < M) dif.insert(l);
			if(c-1 >= 0) dif.insert(c-1);
			if(c+1 < M) dif.insert(c);
			for(auto d : dif) for(int i = 0; i < N; i++) if(A[i][d] > A[i][d+1]) cost--;
			for(int i = 0; i < N; i++) swap(A[i][l], A[i][c]);
			for(auto d : dif) for(int i = 0; i < N; i++) if(A[i][d] > A[i][d+1]) cost++;
			if(cost == 0) ans = {l, c};
			for(auto d : dif) for(int i = 0; i < N; i++) if(A[i][d] > A[i][d+1]) cost--;
			for(int i = 0; i < N; i++) swap(A[i][l], A[i][c]);
			for(auto d : dif) for(int i = 0; i < N; i++) if(A[i][d] > A[i][d+1]) cost++;
		}
		if(ans.ff == -1) cout << "-1\n";
		else cout << ans.ff+1 << " " << ans.ss+1 << "\n";
	}
}

// look at my code
// my code is amazing