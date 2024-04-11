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
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<int> id_x(N, -1), id_y(N, -1);
		int ans = 0;
		for(int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			if(x != y) ans++;
			id_x[x] = i;
			id_y[y] = i;
		}
		vector<int> G[2] = {vector<int>(M, -1), vector<int>(M, -1)};
		for(int i = 0; i < N; i++) if(id_x[i] != id_y[i] && id_x[i] != -1 && id_y[i] != -1) {
			if(G[0][id_x[i]] == -1) G[0][id_x[i]] = id_y[i];
			else G[1][id_x[i]] = id_y[i];
			if(G[0][id_y[i]] == -1) G[0][id_y[i]] = id_x[i];
			else G[1][id_y[i]] = id_x[i];
		}
		vector<char> vis(M, 0);
		for(int i = 0; i < M; i++) if(G[0][i] == -1) vis[i] = 1;
		for(int i = 0; i < M; i++) if(!vis[i] && G[1][i] == -1) {
			int cur = i;
			while(true) {
				vis[cur] = 1;
				if(!vis[G[0][cur]]) cur = G[0][cur];
				else if(G[1][cur] != -1 && !vis[G[1][cur]]) cur = G[1][cur];
				else break;
			}
		}
		for(int i = 0; i < M; i++) if(!vis[i]) {
			ans++;
			static queue<int> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()) {
				for(int k = 0; k < 2; k++) if(G[k][q.front()] != -1 && !vis[G[k][q.front()]]) {
					vis[G[k][q.front()]] = 1;
					q.push(G[k][q.front()]);
				}
				q.pop();
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing