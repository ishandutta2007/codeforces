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
		vector<int> P(N), pos(N);
		for(int i = 0; i < N; i++) {
			cin >> P[i];
			pos[--P[i]] = i;
		}
		if(N == 1) {
			cout << "0\n";
			continue;
		}
		static set<int> S;
		S.clear();
		vector<int> dist_l(N, N+1);
		for(int i = 0; i < N; i++) {
			S.insert(P[i]);
			if(i == 0) {
				dist_l[i] = 0;
				continue;
			}
			if(P[i] == *begin(S)) dist_l[i] = dist_l[pos[*rbegin(S)]]+1;
			else if(P[i] == *rbegin(S)) dist_l[i] = dist_l[pos[*begin(S)]]+1;
		}
		S.clear();
		vector<int> dist_r(N, N+1);
		for(int i = N-1; i >= 0; i--) {
			S.insert(P[i]);
			if(i == N-1) {
				dist_r[i] = 0;
				continue;
			}
			if(P[i] == *begin(S)) dist_r[i] = dist_r[pos[*rbegin(S)]]+1;
			else if(P[i] == *rbegin(S)) dist_r[i] = dist_r[pos[*begin(S)]]+1;
		}
		cout << min(dist_l[pos[0]]+dist_r[pos[N-1]]+1, dist_l[pos[N-1]]+dist_r[pos[0]]+1) << "\n";
	}
}

// look at my code
// my code is amazing