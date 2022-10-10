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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > C_str(N);
	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		C_str[a].push_back({b,c});
	}
	vector< vector<int> > dist(N, vector<int>(N, 1000000000+N));
	priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > q;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(auto c : C_str[i]) {
		if(c.ff <= j) dist[i][j] = min(dist[i][j], c.ss+j-c.ff);
		else dist[i][j] = min(dist[i][j], c.ss+j-c.ff+N);
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) q.push({dist[i][j], {i,j}});
	while(!q.empty()) {
		auto p = q.top();
		q.pop();
		if(p.ff != dist[p.ss.ff][p.ss.ss]) continue;
		int i = p.ss.ff, k = p.ss.ss;
		vector<int> dist_cur = dist[i];
		for(auto c : C_str[k]) {
			int j = (c.ff+dist[i][k])%N;
			int v = dist[i][k] + c.ss;
			dist_cur[j] = min(dist_cur[j], v);
		}
		for(int j = 0; j < N-1; j++) dist_cur[j+1] = min(dist_cur[j+1], dist_cur[j]+1);
		dist_cur[0] = min(dist_cur[0], dist_cur[N-1]+1);
		for(int j = 0; j < N-1; j++) dist_cur[j+1] = min(dist_cur[j+1], dist_cur[j]+1);
		for(int j = 0; j < N; j++) if(dist_cur[j] < dist[i][j]) {
			dist[i][j] = dist_cur[j];
			q.push({dist[i][j], {i,j}});
		}
	}
	for(int i = 0; i < N; i++) dist[i][i] = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cout << dist[i][j] << ((j == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing