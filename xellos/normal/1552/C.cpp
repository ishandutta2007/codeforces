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
		int N, K;
		cin >> N >> K;
		vector<int> id(2*N, -1);
		vector< pair<int, int> > P;
		for(int i = 0; i < K; i++) {
			int x,y;
			cin >> x >> y;
			id[x-1] = id[y-1] = i;
			P.push_back({x-1,y-1});
		}
		vector<int> fr;
		for(int i = 0; i < 2*N; i++) if(id[i] == -1) fr.push_back(i);
		for(int i = 0; i < N-K; i++) {
			id[fr[i]] = id[fr[i+N-K]] = K+i;
			P.push_back({fr[i], fr[i+N-K]});
		}
		int ans = 0;
		for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) {
			vector< pair<int,int> > v;
			v.push_back({P[i].ff,0});
			v.push_back({P[i].ss,0});
			v.push_back({P[j].ff,1});
			v.push_back({P[j].ss,1});
			sort(begin(v), end(v));
			if(v[0].ss == v[2].ss) ans++;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing