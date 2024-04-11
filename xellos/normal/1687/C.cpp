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
		int N, M;
		cin >> N >> M;
		vector<cat> A(N), B(N), D(N+1, 0);
		for(int i = 0; i < N; i++) cin >> A[i];
		for(int i = 0; i < N; i++) cin >> B[i];
		for(int i = 0; i < N; i++) D[i+1] = D[i]+A[i]-B[i];
		vector< vector<int> > I(N+1);
		for(int i = 0; i < M; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			I[l].push_back(r);
			I[r].push_back(l);
		}
		if(D[N] != 0) {
			cout << "NO\n";
			continue;
		}
		set<int> neq0;
		for(int i = 1; i < N; i++) if(D[i] != 0) neq0.insert(i);
		queue< pair<int,int> > qI;
		for(int i = 0; i <= N; i++) for(auto j : I[i]) if(j < i && D[j] == 0 && D[i] == 0) qI.push({j, i});
		while(!qI.empty()) {
			auto [l, r] = qI.front();
			qI.pop();
			auto it = neq0.lower_bound(l);
			while(it != end(neq0) && *it < r) {
				for(auto j : I[*it]) if(D[j] == 0) qI.push({min(j,*it), max(j,*it)});
				D[*it] = 0;
				auto jt = it++;
				neq0.erase(jt);
			}
		}
		cout << (neq0.empty() ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing