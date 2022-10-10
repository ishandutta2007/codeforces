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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

void ask(int v, auto & dist) {
	cout << "? " << v+1 << endl;
	for(int i = 0; i < (int)dist.size(); i++) {
		cin >> dist[v][i];
		dist[i][v] = dist[v][i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector< pair<int,int> > E;
	vector< vector<int> > dist(N, vector<int>(N, N));
	vector<char> in_tree(N, 0);
	ask(0, dist);
	in_tree[0] = 1;
	vector<int> min_dist = dist[0];
	while(true) {
		int id = -1;
		for(int i = 0; i < N; i++) if(!in_tree[i] && min_dist[i] == 2) {
			id = i;
			break;
		}
		if(id == -1) break;
		ask(id, dist);
		int par = -1;
		for(int i = 0; i < N; i++) if(min_dist[i] == 1 && dist[id][i] == 1 && !in_tree[i]) {
			par = i;
			break;
		}
		int pp = -1;
		for(int i = 0; i < N; i++) if(dist[par][i] == 1 && in_tree[i]) {
			pp = i;
			break;
		}
		E.push_back({id, par});
		E.push_back({par, pp});
		in_tree[id] = in_tree[par] = 1;
		for(int i = 0; i < N; i++) if(!in_tree[i]) {
			if(dist[id][i] == dist[pp][i]) dist[par][i] = dist[i][par] = dist[id][i]-1;
			else dist[par][i] = min(dist[id][i], dist[pp][i]) + 1;
		}
		for(int i = 0; i < N; i++) min_dist[i] = min(min_dist[i], dist[id][i]);
		for(int i = 0; i < N; i++) min_dist[i] = min(min_dist[i], dist[par][i]);
	}
	for(int i = 0; i < N; i++) if(!in_tree[i]) {
		for(int j = 0; j < N; j++) if(in_tree[j] && dist[i][j] == 1) {
			E.push_back({i,j});
			break;
		}
	}
	cout << "!" << endl;
	for(int i = 0; i < N-1; i++) cout << E[i].ff+1 << " " << E[i].ss+1 << endl;
}

// look at my code
// my code is amazing