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
#define soclose 1e-11
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
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

struct itree {
	int b;
	vector<cat> mi, addv;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mi.resize(2*b, 0);
		addv.resize(2*b, 0);
	}

	inline void upd(int cur) {
		mi[cur] += addv[cur];
		if(cur < b && addv[cur]) {
			addv[2*cur] += addv[cur];
			addv[2*cur+1] += addv[cur];
		}
		addv[cur] = 0;
	}

	void add(int I_r, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(I_r == r) {
			addv[cur] += val;
			upd(cur);
			return;
		}
		upd(cur);
		int mid = (l+r)/2;
		if(I_r <= mid) {
			add(I_r, val, 2*cur, l, mid);
			upd(2*cur+1);
		}
		else {
			add(I_r, val, 2*cur+1, mid, r);
			addv[2*cur] += val;
			upd(2*cur);
		}
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
	}

	cat get_min(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur);
		if(I_l >= I_r) return OVER9000;
		if(I_l == l && I_r == r) return mi[cur];
		int mid = (l+r)/2;
		cat ret_l = get_min(I_l, I_r, 2*cur, l, mid);
		cat ret_r = get_min(I_l, I_r, 2*cur+1, mid, r);
		return min(ret_l, ret_r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	int MX = 100000;
	vector< vector<int> > divs(MX+1);
	for(int i = 1; i <= MX; i++) for(int j = i; j <= MX; j += i) divs[j].push_back(i);
	vector<int> phi(MX+1, 0);
	phi[1] = 1;
	for(int i = 2; i <= MX; i++) {
		int p = divs[i][1];
		if((i/p)%p == 0) phi[i] = phi[i/p] * p;
		else phi[i] = phi[i/p] * (p-1);
	}
	phi[1] = 0;
	vector< vector<cat> > ans(17, vector<cat>(MX+1, 1LL*MX*MX));
	ans[0][0] = 0;
	for(int i = 1; i <= MX; i++) reverse(begin(divs[i]), end(divs[i]));
	for(int k = 1; k < 17; k++) {
		cat v = ans[k-1][0];
		for(int i = 1; i <= MX; i++) {
			for(auto d : divs[i]) v += phi[i/d];
			ans[k][i] = v;
		}
		if(k == 1) continue;
		itree I(MX);
		I.add(1, 10000000);
		for(int i = 1; i < MX; i++) I.add(i, ans[k-1][i-1]-ans[k-1][i]);
		I.add(MX, ans[k-1][MX-1]);
		for(int i = 1; i <= MX; i++) {
			cat s = 0;
			for(auto d : divs[i]) if(d < i && d > 1) {
				I.add(d, phi[i/d]);
				s += phi[i/d];
				if(s > ans[k-1][MX]) break;
			}
			ans[k][i] = I.get_min(0, MX);
		}
	}
	while(T--) {
		int N,K;
		cin >> N >> K;
		if(K >= 17) cout << N << "\n";
		else cout << ans[K][N]+N << "\n";
	}
}

// look at my code
// my code is amazing