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
		cat A,B,C;
		string S;
		cin >> N >> A >> B >> C >> S;
		int n0l = 0, n0r = 0;
		while(n0l < N && S[n0l] == '0') n0l++;
		while(n0r < N && S[N-1-n0r] == '0') n0r++;
		if(n0l == N) {
			cout << A*(N>1) << "\n";
			continue;
		}
		S = S.substr(n0l, N-n0l-n0r);
		N = S.size();
		vector<int> V;
		for(int i = 1; i < N; i++) if(S[i-1] == '1' && S[i] == '0') {
			int l = 0;
			while(S[i+l] == '0') l++;
			V.push_back(l);
		}
		sort(begin(V), end(V));
		cat ans = 0;
		for(int k = 0; k < 4; k++) for(int s = 0; s < 2; s++) {
			if(k%2 != 0 && n0l == 0) continue;
			if(k/2 != 0 && n0r == 0) continue;
			int suf0 = ((k%2) ? n0l : max(0,n0l-1)) + ((k/2) ? n0r : max(0, n0r-1));
			int n00 = 0, n11 = 0;
			for(int i = 1; i < N; i++) if(S[i] == S[i-1]) {
				if(S[i] == '0') n00++;
				else n11++;
			}
			int s0 = 0;
			for(int i = 0; i <= (int)V.size(); i++) {
				if(i > 0) s0 += V[i-1]-1;
				if(n11 < s0+s) break;
				int n1 = n11+i, n0 = n00+suf0+i;
				if(s == 0) {
					n0 = min(n0, n1+1);
					n1 = min(n1, n0);
				}
				else {
					n1 = min(n1, n0+1);
					n0 = min(n0, n1);
				}
				ans = max(ans, B*n1+A*n0-(A+C)*(i+k%2+k/2));
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing