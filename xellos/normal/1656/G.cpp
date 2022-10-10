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
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<int> cnt(N, 0);
		for(int i = 0; i < N; i++) cnt[--A[i]]++;
		int id_odd = -1, n_odd = 0;
		for(int i = 0; i < N; i++) if(cnt[i]%2) {
			n_odd++;
			id_odd = i;
		}
		if(n_odd > 1 || (n_odd == 1 && N > 1 && cnt[id_odd] == 1 && A[N/2] == id_odd)) {
			cout << "NO\n";
			continue;
		}
		vector<int> last_id(N, -1), P(N);
		for(int i = 0, j = 0; i < N; i++) {
			if(last_id[A[i]] == -1) {
				last_id[A[i]] = i;
				continue;
			}
			P[j] = last_id[A[i]];
			P[N-1-j] = i;
			j++;
			last_id[A[i]] = -1;
		}
		for(int i = 0; i < N; i++) if(last_id[i] >= 0) P[N/2] = last_id[i];
		vector<int> in_cyc(N, -1);
		vector< vector<int> > cyc(N);
		for(int i = 0; i < N; i++) if(in_cyc[i] == -1) {
			int cur = P[i];
			in_cyc[i] = i;
			cyc[i].push_back(i);
			while(cur != i) {
				in_cyc[cur] = i;
				cyc[i].push_back(cur);
				cur = P[cur];
			}
		}
		for(int i = 0; i < N/2; i++) {
			int c1 = in_cyc[i], c2 = in_cyc[N-1-i];
			if(c1 == c2) continue;
			swap(P[i], P[N-1-i]);
			if(cyc[c1].size() < cyc[c2].size()) swap(c1, c2);
			for(auto id : cyc[c2]) {
				in_cyc[id] = c1;
				cyc[c1].push_back(id);
			}
		}
		for(int i = 1; i < N-1-i; i++) {
			int c1 = in_cyc[i], c2 = in_cyc[i-1];
			if(c1 == c2) continue;
			swap(P[i], P[N-1-i]);
			swap(P[i-1], P[N-1-(i-1)]);
			swap(P[i], P[i-1]);
			swap(P[N-1-i], P[N-1-(i-1)]);
			swap(P[i], P[N-1-i]);
			if(cyc[c1].size() < cyc[c2].size()) swap(c1, c2);
			for(auto id : cyc[c2]) {
				in_cyc[id] = c1;
				cyc[c1].push_back(id);
			}
		}
		if(N%2) for(int i = 0; i < N/2; i++) if(A[P[i]] == A[P[N/2]]) {
			int c1 = in_cyc[i], c2 = in_cyc[N/2];
			if(c1 == c2) break;
			swap(P[i], P[N/2]);
			if(cyc[c1].size() < cyc[c2].size()) swap(c1, c2);
			for(auto id : cyc[c2]) {
				in_cyc[id] = c1;
				cyc[c1].push_back(id);
			}
			break;
		}
		cout << "YES\n";
		for(int i = 0; i < N; i++) cout << P[i]+1 << ((i == N-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing