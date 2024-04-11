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
#define OVER9000 1234567890LL
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

class itree {
	vector<int> min_val, add;
	int b;

	void push(int cur) {
		min_val[cur] += add[cur];
		if(cur >= b) {
			add[cur] = 0;
			return;
		}
		add[2*cur] += add[cur];
		add[2*cur+1] += add[cur];
		add[cur] = 0;
	}

	void range_add(int I_l, int I_r, int val, int l, int r, int cur) {
		push(cur);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return;
		if(I_l == l && I_r == r) {
			add[cur] += val;
			push(cur);
			return;
		}
		int mid = (l+r)/2;
		range_add(I_l, I_r, val, l, mid, 2*cur);
		range_add(I_l, I_r, val, mid, r, 2*cur+1);
		min_val[cur] = min(min_val[2*cur], min_val[2*cur+1]);
	}

public:
	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		min_val.resize(2*b, OVER9000);
		add.resize(2*b, 0);
	}

	void pref_add(int pos, int val) {
		// add val to [0, pos]
		range_add(0, pos+1, val, 0, b, 1);
	}

	int get_min() {
		return min_val[1];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<int> ids_z;
		for(int i = 0; i < N; i++) if(A[i] == 0) ids_z.push_back(i);
		int H = ids_z.size()/2;
		vector<int> r_max(N, -1);
		for(int i = N-2; i >= 0; i--) {
			r_max[i] = r_max[i+1];
			while(r_max[i] < H-1 && ids_z[ids_z.size()-1-(r_max[i]+1)] > i) r_max[i]++;
		}
		itree I(H);
		I.pref_add(H-1, H-OVER9000);
		for(int i = 0; i < H; i++) I.pref_add(i, -1);
		vector<int> l_pos(N, N);
		int ans = H;
		for(int i = H-1, r_nz = N-1; i >= 0; i--) {
			while(r_nz > ids_z[i]) {
				if(A[r_nz] != 0) {
					if(l_pos[A[r_nz]-1] != N) I.pref_add(r_max[l_pos[A[r_nz]-1]], -1);
					l_pos[A[r_nz]-1] = r_nz;
					I.pref_add(r_max[l_pos[A[r_nz]-1]], 1);
				}
				r_nz--;
			}
			ans = min(ans, i + I.get_min());
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing