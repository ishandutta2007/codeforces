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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cat M;
		cin >> N >> M;
		vector<cat> X(N), P(N);
		vector< pair<cat,int> > ch(3*N);
		for(int i = 0; i < N; i++) {
			cin >> X[i] >> P[i];
			ch[3*i] = {X[i]-P[i], 1};
			ch[3*i+1] = {X[i], -2};
			ch[3*i+2] = {X[i]+P[i], 1};
		}
		sort(begin(ch), end(ch));
		cat H = 0, sl = 0, l = ch[3*N-1].ff, r = ch[0].ff;
		for(int i = 1; i < 3*N; i++) {
			sl += ch[i-1].ss;
			H += (ch[i].ff-ch[i-1].ff) * sl;
			if(H > M) {
				l = min(l, ch[i].ff-(H-M));
				r = max(r, ch[i].ff+(H-M));
			}
		}
		string ans;
		for(int i = 0; i < N; i++) ans += (X[i]-P[i] <= l && X[i]+P[i] >= r) ? '1' : '0';
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing