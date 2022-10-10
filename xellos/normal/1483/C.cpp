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

struct info {
	int b, h, st;
	cat mx;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i = 0; i < N; i++) cin >> H[i];
	vector<int> B(N);
	for(int i = 0; i < N; i++) cin >> B[i];
	vector<cat> ans(N+1, -OVER9000);
	ans[0] = 0;
	vector<info> I;
	multiset<cat> S;
	for(int i = 0; i < N; i++) {
		int a = i;
		cat max_val = ans[i];
		while(!I.empty() && I.back().h > H[i]) {
			max_val = max(max_val, I.back().mx);
			S.erase(S.find(I.back().mx + I.back().b));
			a = I.back().st;
			I.pop_back();
		}
		S.insert(max_val + B[i]);
		I.push_back({B[i], H[i], a, max_val});
		ans[i+1] = max(ans[i+1], *rbegin(S));
	}
	cout << ans[N] << "\n";
}

// look at my code
// my code is amazing