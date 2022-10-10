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
#define OVER9000 1234567890
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
	int N, A, B, K = 0;
	string S;
	cin >> N >> A >> B >> S;
	vector<int> M_id(30, -1);
	vector<char> C_id;
	for(int i = 0; i < N; i++) if(M_id[S[i]-'a'] == -1) {
		M_id[S[i]-'a'] = K;
		C_id.push_back(S[i]);
		K++;
	}
	vector<short> mx0(K, -1), mi0(K, N), sz0(K, 0);
	for(int i = 0; i < N; i++) {
		int id = M_id[S[i]-'a'];
		sz0[id]++;
		mi0[id] = min(1*mi0[id], i);
		mx0[id] = max(1*mx0[id], i);
	}
	vector<short> mx(1<<K, -1), mi(1<<K, N), sz(1<<K, 0);
	for(int i = 0, b = 0; i < (1<<K); i++) {
		while((1<<b) <= i) b++;
		for(int j = b; j < K; j++) {
			mi[i|(1<<j)] = min(mi[i], mi0[j]);
			mx[i|(1<<j)] = max(mx[i], mx0[j]);
			sz[i|(1<<j)] = sz[i] + sz0[j];
		}
	}
	vector< vector<int> > first0(K, vector<int>(N,0));
	for(int i = 0; i < K; i++) {
		first0[i][mi0[i]] = 1<<M_id[S[mi0[i]]-'a'];
		for(int j = mi0[i]+1; j < N; j++) 
			first0[i][j] = first0[i][j-1] | (1<<M_id[S[j]-'a']);
	}
	vector<int> first(1<<K, 0);
	for(int i = 1; i < (1<<K); i++) {
		int id_mi = M_id[S[mi[i]]-'a'];
		int b = first0[id_mi][mx0[id_mi]] & i;
		while(true) {
			int b_nw = (b | first0[id_mi][mx[b]]) & i;
			if(b_nw == b) break;
			b = b_nw;
		}
		first[i] = b;
	}
	vector<char> reach(1<<K, 0), reach_s(1<<K, 0);
	reach[0] = 1;
	for(int i = 1; i < (1<<K)-1; i++) {
		if((mx[i]-mi[i]+1)*A > B*sz[i]) continue;
		for(int t = 0; t < K; t++) if((i>>t)&1) {
			if(reach_s[i-(1<<t)]) {
				reach[i] = 1;
				break;
			}
			static int bl[30];
			int br = i-(1<<t), l = 0;
			while(br) {
				bl[l] = first[br];
				br -= first[br];
				l++;
			}
			static char ok[30];
			ok[0] = 1;
			memset(ok+1, 0, l);
			for(int j = 0; j < l; j++) if(ok[j]) {
				int b = 0;
				for(int k = j; k < l; k++) {
					b += bl[k];
					ok[k+1] |= reach[b];
				}
			}
			if(ok[l]) {
				reach_s[i-(1<<t)] = 1;
				reach[i] = 1;
				break;
			}
		}
		reach_s[i] |= reach[i];
	}
	vector<char> ans;
	for(int t = 0; t < K; t++) {
		static int bl[30];
		int br = (1<<K)-1-(1<<t), l = 0;
		while(br) {
			bl[l] = first[br];
			br -= first[br];
			l++;
		}
		static char ok[30];
		ok[0] = 1;
		memset(ok+1, 0, l);
		for(int j = 0; j < l; j++) if(ok[j]) {
			int b = 0;
			for(int k = j; k < l; k++) {
				b += bl[k];
				ok[k+1] |= reach[b];
			}
		}
		if(ok[l]) ans.push_back(C_id[t]);
	}
	sort(begin(ans), end(ans));
	cout << ans.size();
	for(int i = 0; i < (int)ans.size(); i++) cout << ' ' << ans[i];
	cout << '\n';
}

// look at my code
// my code is amazing