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
	int N, K;
	cin >> N >> K;
	if(N == 1) {
		cout << "ACCEPTED\n";
		return 0;
	}
	vector< vector<int> > R(K);
	vector< vector<cat> > RS(K);
	vector<cat> S(K, 0);
	srand(N);
	for(int i = 0; i < K; i++) {
		int l;
		cin >> l;
		R[i].resize(l);
		RS[i].resize(l+1, 0);
		for(int j = 0; j < l; j++) {
			cin >> R[i][j];
			srand(rand()+R[i][j]);
			RS[i][j+1] = RS[i][j];
			RS[i][j+1] |= 1LL<<(--R[i][j]);
		}
		S[i] = RS[i][l];
	}
	for(int rep = 0; rep < 1000; rep++) {
		vector<char> V(N);
		for(int i = 0; i < N; i++) V[i] = rand()%2;
		for(int i = 0; i < K; i++) {
			int n0 = 0, n1 = 0;
			for(int j = 0; j < (int)R[i].size(); j++) {
				if(V[R[i][j]]) n1++;
				else n0++;
			}
			for(int j = 0; j < (int)R[i].size(); j++) {
				if(j < n0) V[R[i][j]] = 0;
				else V[R[i][j]] = 1;
			}
		}
		bool ok = true;
		for(int i = 1; i < N; i++) if(V[i] == 0 && V[i-1] == 1) ok = false;
		if(!ok) {
			cout << "REJECTED\n";
			return 0;
		}
	}
	vector< pair<cat,cat> > states = {{0,0}};
	for(int k = 0; k < K; k++) {
		static vector< pair<cat,cat> > states_nw;
		states_nw.clear();
		for(auto st : states) {
			cat b0 = st.ff, b1 = st.ss, bq = (1LL<<N)-1-st.ff-st.ss;
			cat o0 = S[k]&b0, o1 = S[k]&b1, oq = S[k]&bq;
			int sz0 = __builtin_popcountll(o0);
			int sz1 = __builtin_popcountll(o1);
			int sz = __builtin_popcountll(oq);
			for(int i = 0; i <= sz; i++) {
				int n0 = sz0 + i, n1 = sz1 + sz-i;
				cat b0_nw = (b0^o0)|RS[k][n0], b1_nw = (b1^o1)|(S[k]^RS[k][n0]);
				states_nw.push_back({b0_nw, b1_nw});
			}
		}
		states = states_nw;
		sort(begin(states), end(states));
		auto it = unique(begin(states), end(states));
		int sz = it - begin(states);
		states.resize(sz);
	}
	for(auto st : states) {
		int n0 = __builtin_popcountll(st.ff);
		int n1 = __builtin_popcountll(st.ss);
		if(st.ff != (1LL<<n0)-1 || st.ff+st.ss != (1LL<<N)-1) {
			cout << "REJECTED\n";
			return 0;
		}
	}
	cout << "ACCEPTED\n";
}

// look at my code
// my code is amazing