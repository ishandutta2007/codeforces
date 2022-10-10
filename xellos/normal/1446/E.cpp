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

void DFS(int R, auto & G, auto & vis, auto & C) {
	vis[R] = 1;
	for(auto v : G[R]) if(!vis[v] && C[v]) DFS(v, G, vis, C);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int V = 505*505;
	vector< vector<int> > G(V);
	for(int i = -2; i <= 502; i++) for(int j = -2; j <= 502; j++) {
		int cur = (i+2)*505 + (j+2);
		if(i >= -1) G[cur].push_back((i+1)*505 + (j+2));
		if(i <= 501) G[cur].push_back((i+3)*505 + (j+2));
		int adjx = i+1, adjy = j-1;
		if(i%2 != 0) adjx = i-1, adjy = j+1;
		if(adjx >= -2 && adjy >= -2 && adjx <= 502 && adjy <= 502)
			G[cur].push_back((adjx+2)*505 + (adjy+2));
	}
	int N;
	cin >> N;
	vector<char> C(V, 0);
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		C[(x+2)*505 + (y+2)] = 1;
	}
	vector<int> deg(V, 0);
	queue<int> q;
	for(int i = 0; i < V; i++) if(!C[i])
		for(auto v : G[i]) deg[i] += (C[v] == 0);
	for(int i = -2; i <= 502; i++) {
		deg[(i+2)*505 + (-2+2)] += 100;
		deg[(i+2)*505 + (502+2)] += 100;
		deg[(-2+2)*505 + (i+2)] += 100;
		deg[(502+2)*505 + (i+2)] += 100;
	}
	for(int i = 0; i < V; i++) if(!C[i] && deg[i] <= 1) {
		C[i] = 3;
		q.push(i);
	}
	while(!q.empty()) {
		for(auto v : G[q.front()]) if(!C[v]) {
			deg[v]--;
			if(deg[v] <= 1) {
				C[v] = 3;
				q.push(v);
			}
		}
		q.pop();
	}
	int ans = 0, n1 = 0, t1 = 0, e1 = 0;
	for(int i = 0; i < V; i++) if(C[i]) {
		n1++;
		for(auto v : G[i]) if(v < i) e1 += C[v] & 1;
		if(C[i] == 1) for(auto v : G[i]) ans += (C[v] != 1);
	}
	vector<char> vis(V, 0);
	for(int i = 0; i < V; i++) if(C[i] && !vis[i]) {
		t1++;
		DFS(i, G, vis, C);
	}
	ans -= 2*t1;
	for(int i = 0; i < V; i++) if(C[i] == 3) {
		bool bip = true;
		for(auto v : G[i]) {
			if(C[v] != 1) bip = false;
			else for(auto u : G[v]) if(u != i && C[u]) bip = false;
		}
		if(bip) ans -= 2;
	}
	if(e1 != n1-t1) cout << "SICK\n";
	else cout << "RECOVERED\n" << ans << "\n";
}

// look at my code
// my code is amazing