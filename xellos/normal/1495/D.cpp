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
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);
	}
	vector< vector<short> > dist(N, vector<short>(N, -1));
	for(int i = 0; i < N; i++) {
		dist[i][i] = 0;
		static queue<int> q;
		q.push(i);
		while(!q.empty()) {
			for(auto v : G[q.front()]) if(dist[i][v] == -1) {
				dist[i][v] = dist[i][q.front()]+1;
				q.push(v);
			}
			q.pop();
		}
	}
	cat mod = 998244353;
	vector< vector<cat> > ans(N, vector<cat>(N, 0));
	for(int x = 0; x < N; x++) for(int y = 0; y < N; y++) {
		if(y < x) {
			cout << ans[y][x] << ' ';
			continue;
		}
		static vector<char> in_spath(N);
		int n_spath = 0;
		for(int i = 0; i < N; i++) {
			in_spath[i] = (dist[x][y] == dist[x][i]+dist[y][i]);
			n_spath += in_spath[i];
		}
		if(dist[x][y]+1 != n_spath) {
			cout << 0 << ((y == N-1) ? '\n' : ' ');
			continue;
		}
		ans[x][y] = 1;
		for(int i = 0; i < N; i++) if(!in_spath[i]) {
			int cur = 0;
			for(auto v : G[i]) cur += (dist[x][v] == dist[x][i]-1 && dist[y][v] == dist[y][i]-1);
			ans[x][y] = ans[x][y] * cur % mod;
		}
		cout << ans[x][y] << ((y == N-1) ? '\n' : ' ');
	}
}

// look at my code
// my code is amazing