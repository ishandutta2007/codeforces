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
		int N;
		string S;
		cin >> N >> S;
		int l1 = N, r0 = -1;
		for(int i = 0; i < N; i++) if(S[i] == '1') {
			l1 = i;
			break;
		}
		for(int i = N-1; i >= 0; i--) if(S[i] == '0') {
			r0 = i;
			break;
		}
		if(r0 < l1) {
			cout << "0\n";
			continue;
		}
		vector<int> D(N+1, 0);
		for(int i = 0; i < N; i++) D[i+1] = D[i] + ((S[i] == '0') ? 1 : -1);
		int ans = 0;
		vector<int> L(2*N+1, N+1), R(2*N+1, -1);
		for(int i = 0; i <= N; i++) {
			L[D[i]+N] = min(L[D[i]+N], i);
			R[D[i]+N] = max(R[D[i]+N], i);
		}
		int ls = l1, rs = N-1-r0;
		while(l1 < r0) {
			pair<int,int> Il{0, l1}, Ir{D[N], D[N]+N-1-r0};
			ans++;
			if(Il.ff <= Ir.ff) {
				if(Il.ss >= Ir.ff) break;
				int ls_nw = R[Il.ss+N];
				for(int i = ls; i < ls_nw; i++) if(S[i] == '0') l1++;
				ls = ls_nw;
			}
			else {
				if(Ir.ss >= Il.ff) break;
				int rs_nw = N-L[Ir.ss+N];
				for(int i = N-1-rs; i > N-1-rs_nw; i--) if(S[i] == '1') r0--;
				rs = rs_nw;
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing