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
		vector<int> A(N);
		vector< vector<int> > id(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			id[--A[i]].push_back(i);
		}
		vector< pair<int,int> > V(N);
		for(int i = 0; i < N; i++) V[i] = {id[i].size(), i};
		sort(rbegin(V), rend(V));
		stack< pair<int,int> > st;
		st.push(V[0]);
		vector<int> pos(N, 0), B(N);
		for(int i = 1; i < N; i++) if(V[i].ff) {
			int d_in = V[i].ff;
			while(d_in > 0) {
				int x = min(d_in, st.top().ff);
				pair<int,int> p = st.top();
				st.pop();
				p.ff -= x;
				d_in -= x;
				if(p.ff) st.push(p);
				// x krat p.ss->V[i].ss
				for(int j = 0; j < x; j++) {
					B[id[p.ss][pos[p.ss]++]] = V[i].ss;
				}
			}
			st.push(V[i]);
		}
		while(!st.empty()) {
			pair<int,int> p = st.top();
			st.pop();
			// p.ff krat p.ss->V[0].ss
			for(int j = 0; j < p.ff; j++) {
				B[id[p.ss][pos[p.ss]++]] = V[0].ss;
			}
		}
		for(int i = 0; i < N; i++) cout << B[i]+1 << ((i+1 == N) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing