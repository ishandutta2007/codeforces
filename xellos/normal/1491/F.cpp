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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int l = 0;
		vector<int> A(N, 0);
		while(l < N-1) {
			cout << "? 1 " << N-1-l << "\n" << l+1 << "\n";
			for(int i = l+1; i < N; i++) cout << i+1 << ((i == N-1) ? "" : " ");
			cout << endl;
			int F;
			cin >> F;
			if(F == 0) {
				l++;
				continue;
			}
			A[l] = 1;
			for(int i = l+1; i < N-1; i++) {
				cout << "? 1 1\n" << i+1 << "\n" << l+1 << endl;
				cin >> A[i];
			}
			A[N-1] = F;
			for(int i = l+1; i < N-1; i++) A[N-1] -= A[i];
			break;
		}
		int nl = 0;
		if(l) {
			cout << "? 1 " << l << "\n" << l+1 << "\n";
			for(int i = 0; i < l; i++) cout << i+1 << ((i == l-1) ? "" : " ");
			cout << endl;
			cin >> nl;
		}
		if(nl) {
			int l1 = 0, r1 = l;
			int r = l;
			while(A[r]+A[l] != 0) r++;
			if(A[l] != nl) swap(l, r);
			while(r1-l1 > 1) {
				int m1 = (2 * l1 + r1 + 2) / 3;
				int m2 = (m1 + r1 + 1) / 2;
				cout << "? " << 1+m1-l1 << " " << 1+m2-m1 << "\n" << l+1;
				for(int i = l1; i < m1; i++) cout << " " << i+1;
				cout << "\n" << r+1;
				for(int i = m1; i < m2; i++) cout << " " << i+1;
				cout << endl;
				int F;
				cin >> F;
				if(F == 0) l1 = m1, r1 = m2;
				else if(F == -2) r1 = m1;
				else l1 = m2;
			}
			A[l1] = nl;
		}
		vector<int> ans;
		for(int i = 0; i < N; i++) if(A[i] == 0) ans.push_back(i);
		cout << "! " << ans.size();
		for(int i = 0; i < (int)ans.size(); i++) cout << " " << ans[i]+1;
		cout << endl;
	}
}

// look at my code
// my code is amazing