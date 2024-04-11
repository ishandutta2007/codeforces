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
	vector<int> SG(200, 0);
	for(int i = 1; i < 200; i++) {
		vector<char> b(32, 0);
		for(int k = 0; k <= i-2; k++) b[SG[k]^SG[i-2-k]] = 1;
		while(b[SG[i]]) SG[i]++;
	}
	int T;
	cin >> T;
	while(T--) {
		int N;
		string S;
		cin >> N >> S;
		int nR = 0, nB = 0;
		for(int i = 0; i < N; i++) {
			if(S[i] == 'R') nR++;
			else nB++;
		}
		if(nR != nB) {
			cout << ((nR > nB) ? "Alice\n" : "Bob\n");
			continue;
		}
		vector<int> L;
		for(int l = 0; l < N; l++) {
			int r = l+1;
			while(r < N) {
				if(S[r] == S[l] && (r-l)%2 != 0) break;
				if(S[r] != S[l] && (r-l)%2 == 0) break;
				r++;
			}
			L.push_back(r-l);
			l = r-1;
		}
		int SG_tot = 0;
		for(auto l : L) {
			if(l >= 200) l -= (l-100)/34*34;
			SG_tot ^= SG[l];
		}
		cout << (SG_tot ? "Alice\n" : "Bob\n");
	}
}

// look at my code
// my code is amazing