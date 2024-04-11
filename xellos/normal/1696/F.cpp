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

bool test(const auto & G, const auto & L, const auto & in_L) {
	int N = G.size();
	for(int i = 0; i < N; i++) {
		vector<int> par(N, 0);
		par[i] = i;
		vector<int> l_cur = {i};
		while(!l_cur.empty()) {
			int lj = in_L[i][l_cur[0]];
			if(L[i][lj].size() != l_cur.size()) return false;
			for(auto v : l_cur) if(in_L[i][v] != lj) return false;
			vector<int> l_nxt;
			for(auto v : l_cur) for(auto u : G[v]) if(u != par[v]) {
				par[u] = v;
				l_nxt.push_back(u);
			}
			l_cur = l_nxt;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	char eq[100][100][100];
	while(T--) {
		int N;
		cin >> N;
		for(int i = 0; i < N-1; i++) for(int j = 1; j < N-i; j++) {
			string s;
			cin >> s;
			for(int k = 0; k < N; k++) eq[k][i][i+j] = eq[k][i+j][i] = s[k]-'0';
		}
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) eq[i][j][j] = 1;
		vector< vector< vector<int> > > L(N);
		vector< vector<int> > in_L(N, vector<int>(N, -1));
		bool ok = true;
		for(int i = 0; i < N; i++) {
			vector<char> vis(N, 0);
			for(int j = 0; j < N; j++) if(!vis[j]) {
				vector<int> v;
				for(int k = 0; k < N; k++) if(eq[i][j][k]) {
					if(vis[k]) ok = false;
					v.push_back(k);
					in_L[i][k] = L[i].size();
					vis[k] = 1;
				}
				if(!ok) break;
				L[i].push_back(v);
			}
			if(!ok) break;
			for(int j = 0; j < N; j++) for(int k = 0; k < N; k++) {
				char b = (in_L[i][j] == in_L[i][k]);
				if(b != eq[i][j][k]) ok = false;
			}
			if(!ok) break;
		}
		if(!ok) {
			cout << "No\n";
			continue;
		}
		int R = 0;
		vector< pair<int,int> > ans;
		for(auto l : L[R]) {
			if(l[0] == R) continue;
			ok = true;
			vector< pair<int,int> > cur;
			vector< vector<int> > G(N);
			vector<char> vis(N, 0);
			vis[R] = 1;
			for(auto v : l) {
				vis[v] = 1;
				cur.push_back({R, v});
				G[R].push_back(v);
				G[v].push_back(R);
			}
			auto l_cur = l;
			while(!l_cur.empty()) {
				vector<int> l_nxt;
				for(auto v : l_cur) {
					int p = G[v][0];
					int pl = in_L[v][p];
					for(auto u : L[v][pl]) {
						if(u == p) continue;
						if(vis[u]) {
							ok = false;
							break;
						}
						vis[u] = 1;
						cur.push_back({v, u});
						G[v].push_back(u);
						G[u].push_back(v);
						l_nxt.push_back(u);
					}
				}
				if(!ok) break;
				for(auto v : l_nxt) vis[v] = 1;
				l_cur = l_nxt;
			}
			if((int)cur.size() != N-1) continue;
			if(ok && test(G, L, in_L)) {
				ans = cur;
				// break;
			}
		}
		if(ans.empty()) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		for(int i = 0; i < N-1; i++) cout << ans[i].ff+1 << " " << ans[i].ss+1 << "\n";
	}
}

// look at my code
// my code is amazing