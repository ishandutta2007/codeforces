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

struct itree {
	vector<int> mi;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mi.resize(2*b, N+1);
	}

	void put(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) {
			mi[cur] = min(mi[cur], val);
			return;
		}
		int mid = (l+r)/2;
		if(pos < mid) put(pos, val, 2*cur, l, mid);
		else put(pos, val, 2*cur+1, mid, r);
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
	}

	int get(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return b+1;
		if(I_l == l && I_r == r) return mi[cur];
		int mid = (l+r)/2;
		return min(get(I_l, I_r, 2*cur, l, mid), get(I_l, I_r, 2*cur+1, mid, r));
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	set<int> live;
	for(int i = 0; i < N; i++) live.insert(i);
	itree I(N);
	for(int q = 0; q < Q; q++) {
		int tp;
		cin >> tp;
		if(tp == 0) {
			int l,r,st;
			cin >> l >> r >> st;
			l--;
			if(st == 0) {
				while(true) {
					auto it = live.lower_bound(l);
					if(it == end(live) || *it >= r) break;
					live.erase(it);
				}
			}
			else I.put(l, r);
		}
		else {
			int pos;
			cin >> pos;
			pos--;
			auto it = live.find(pos);
			if(it == end(live)) cout << "NO\n";
			else {
				int r = N, l = 0;
				if(it != begin(live)) {
					it--;
					l = *it+1;
					it++;
				}
				it++;
				if(it != end(live)) r = *it;
				if(I.get(l, pos+1) <= r) cout << "YES\n";
				else cout << "N/A\n";
			}
		}
	}
}

// look at my code
// my code is amazing