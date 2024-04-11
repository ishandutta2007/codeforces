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
		int N;
		cin >> N;
		int lm, rm, c;
		cin >> lm >> rm >> c;
		map< pair<int,int>, int> Ms;
		map<int, int> Ml, Mr;
		Ms[{lm,rm}] = c;
		Ml[lm] = Mr[rm] = c;
		cout << c << "\n";
		for(int i = 1; i < N; i++) {
			int l, r;
			cin >> l >> r >> c;
			lm = min(lm, l);
			rm = max(rm, r);
			if(Ms.find({l,r}) == end(Ms)) Ms[{l,r}] = c;
			else Ms[{l,r}] = min(Ms[{l,r}], c);
			if(Ml.find(l) == end(Ml)) Ml[l] = c;
			else Ml[l] = min(Ml[l], c);
			if(Mr.find(r) == end(Mr)) Mr[r] = c;
			else Mr[r] = min(Mr[r], c);
			int ans = Ml[lm] + Mr[rm];
			if(Ms.find({lm,rm}) != end(Ms)) ans = min(ans, Ms[{lm,rm}]);
			cout << ans << "\n";
		}
	}
}

// look at my code
// my code is amazing