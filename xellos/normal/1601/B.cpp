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
#define soclose 1e-11
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

struct itree {
	vector< pair<int,int> > mi;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mi.resize(2*b, {b, 0});
	}

	void set(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) {
			mi[cur] = {val, l};
			return;
		}
		int mid = (l+r)/2;
		if(mid <= pos) set(pos, val, 2*cur+1, mid, r);
		else set(pos, val, 2*cur, l, mid);
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
	}

	pair<int,int> get_min(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return {b, 0};
		if(I_l == l && I_r == r) return mi[cur];
		int mid = (l+r)/2;
		return min(get_min(I_l, I_r, 2*cur, l, mid), get_min(I_l, I_r, 2*cur+1, mid, r));
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N+1, 0);
	for(int i = 1; i <= N; i++) cin >> A[i];
	vector<int> B(N+1, 0);
	for(int i = 1; i <= N; i++) cin >> B[i];
	vector< vector<int> > unslip(N+1);
	for(int i = 0; i <= N; i++) unslip[i+B[i]].push_back(i);
	set<int> Q;
	for(int i = 1; i <= N; i++) Q.insert(i);
	itree I(N+1);
	for(int i = 0; i <= N; i++) I.set(i, i-A[i]);
	vector<int> dist(N+1, N+1);
	vector< pair<int,int> > prev(N+1);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto u : unslip[v]) while(true) {
			auto [l, id] = I.get_min(u, N+1);
			if(l > u) break;
			I.set(id, N+1);
			if(dist[id] == N+1) {
				dist[id] = dist[v]+1;
				prev[id] = {u, v};
				q.push(id);
			}
		}
	}
	if(dist[N] > N) {
		cout << "-1\n";
		return 0;
	}
	cout << dist[N] << "\n";
	int cur = N;
	for(int i = 0; i < dist[N]; i++) {
		cout << prev[cur].ff << ((i == dist[N]-1) ? "\n" : " ");
		cur = prev[cur].ss;
	}
}

// look at my code
// my code is amazing