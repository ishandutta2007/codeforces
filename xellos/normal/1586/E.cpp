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

void DFS(int v, auto & G, auto & par) {
	for(auto s : G[v]) if(par[s] == -1) {
		par[s] = v;
		DFS(s, G, par);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int x,y;
		cin >> x >> y;
		G[--x].push_back(--y);
		G[y].push_back(x);
	}
	int Q;
	cin >> Q;
	vector< pair<int,int> > qu(Q);
	vector<char> upd(N, 0);
	for(int i = 0; i < Q; i++) {
		int a,b;
		cin >> a >> b;
		upd[a-1] ^= 1;
		upd[b-1] ^= 1;
		qu[i] = {a-1,b-1};
	}
	bool ok = true;
	for(int i = 0; i < N; i++) if(upd[i]) ok = false;
	if(!ok) {
		int d = 0;
		for(int i = 0; i < N; i++) d += upd[i];
		cout << "NO\n" << d/2 << "\n";
		return 0;
	}
	cout << "YES\n";
	vector<int> par(N, -1);
	par[0] = 0;
	DFS(0, G, par);
	for(int i = 0; i < Q; i++) {
		static vector<int> va;
		va.clear();
		while(qu[i].ff) {
			va.push_back(qu[i].ff);
			qu[i].ff = par[qu[i].ff];
		}
		va.push_back(0);
		static vector<int> vb;
		vb.clear();
		while(qu[i].ss) {
			vb.push_back(qu[i].ss);
			qu[i].ss = par[qu[i].ss];
		}
		vb.push_back(0);
		while((int)va.size() > 1 && (int)vb.size() > 1 && va[va.size()-2] == vb[vb.size()-2]) {
			va.pop_back();
			vb.pop_back();
		}
		int c = va.back();
		va.pop_back();
		vb.pop_back();
		reverse(begin(vb), end(vb));
		cout << (int)va.size()+(int)vb.size()+1 << "\n";
		for(auto x : va) cout << x+1 << " ";
		cout << c+1;
		for(auto x : vb) cout << " " << x+1;
		cout << "\n";
	}
}

// look at my code
// my code is amazing