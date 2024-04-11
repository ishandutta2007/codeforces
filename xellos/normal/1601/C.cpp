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
	vector<int> mi, addv;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mi.resize(2*b, 0);
		addv.resize(2*b, 0);
	}

	void upd(int cur) {
		mi[cur] += addv[cur];
		if(cur < b) {
			addv[2*cur] += addv[cur];
			addv[2*cur+1] += addv[cur];
		}
		addv[cur] = 0;
	}

	void add(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addv[cur] += val;
			upd(cur);
			return;
		}
		upd(cur);
		if(I_l >= I_r) return;
		int mid = (l+r)/2;
		add(I_l, I_r, val, 2*cur, l, mid);
		add(I_l, I_r, val, 2*cur+1, mid, r);
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
	}

	int get_min(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur);
		if(I_l >= I_r) return b;
		if(I_l == l && I_r == r) return mi[cur];
		int mid = (l+r)/2;
		int ret = min(get_min(I_l, I_r, 2*cur, l, mid), get_min(I_l, I_r, 2*cur+1, mid, r));
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
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
		vector<int> A(N), B(M);
		for(int i = 0; i < N; i++) cin >> A[i];
		for(int i = 0; i < M; i++) cin >> B[i];
		sort(begin(B), end(B));
		vector< pair<int,int> > As(N);
		for(int i = 0; i < N; i++) As[i] = {A[i], i};
		sort(begin(As), end(As));
		cat ans = 0;
		fin F(N, 0);
		for(int i = N-1; i >= 0; i--) {
			ans += F.get(As[i].ss);
			F.put(As[i].ss, 1);
		}
		itree I(N+1);
		for(int i = 0; i < N; i++) I.add(As[i].ss+1, N+1, 1);
		for(int i = 0, j = 0, p = 0; i < N; i++) {
			while(j < M && B[j] < As[i].ff) {
				ans += I.get_min(0, N+1);
				j++;
			}
			I.add(As[i].ss+1, N+1, -1);
			if(i == N-1 || As[i+1].ff != As[i].ff) {
				p++;
				while(j < M && B[j] == As[i].ff) {
					ans += I.get_min(0, N+1);
					j++;
				}
				for(int j = i; j > i-p; j--) I.add(0, As[j].ss+1, 1);
				p = 0;
			}
			else p++;
			if(i == N-1) while(j < M) {
				ans += I.get_min(0, N+1);
				j++;
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing