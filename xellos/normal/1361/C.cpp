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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, auto & G, auto & GE, auto & cyc, auto & used) {
	while(!GE[R].empty()) {
		while(!GE[R].empty() && used[GE[R].back().ff/2]) {
			GE[R].pop_back();
			G[R].pop_back();
		}
		if(GE[R].empty()) break;
		auto cur = GE[R].back();
		int s = G[R].back();
		GE[R].pop_back();
		G[R].pop_back();
		used[cur.ff/2] = 1;
		DFS(s, G, GE, cyc, used);
		cyc.push_back(cur.ss);
		cyc.push_back(cur.ff);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > A(N);
	for(int i = 0; i < N; i++) cin >> A[i].ff >> A[i].ss;
	for(int b = 20; b >= 0; b--) {
		vector< pair<int, int> > B(N);
		int m = (1<<b)-1;
		for(int i = 0; i < N; i++) B[i].ff = A[i].ff & m, B[i].ss = A[i].ss & m;
		vector< vector<int> > G(1<<b);
		vector<int> occ(1<<b, 0);
		for(int i = 0; i < N; i++) {
			occ[B[i].ff]++, occ[B[i].ss]++;
			G[B[i].ff].push_back(B[i].ss);
			G[B[i].ss].push_back(B[i].ff);
		}
		bool ok = true;
		for(int j = 0; j < (1<<b); j++) if(occ[j]%2 != 0) ok = false;
		if(!ok) continue;
		int R = 0;
		for(int i = 0; i < (1<<b); i++) if(occ[i]) {
			R = i;
			vector<char> vis(1<<b, 0);
			static queue<int> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()) {
				for(auto x : G[q.front()]) if(!vis[x]) {
					vis[x] = 1;
					q.push(x);
				}
				q.pop();
			}
			for(int j = 0; j < (1<<b); j++) if(occ[j] && !vis[j]) ok = false;
			break;
		}
		if(!ok) continue;
		cout << b << "\n";
		vector< vector< pair<int, int> > > GE(1<<b);
		for(int i = 0; i < N; i++) {
			GE[B[i].ff].push_back({2*i, 2*i+1});
			GE[B[i].ss].push_back({2*i+1, 2*i});
		}
		vector<char> used(N, 0);
		vector<int> cyc;
		DFS(R, G, GE, cyc, used);
		for(int i = 0; i < 2*N; i++) cout << cyc[i]+1 << ((i == 2*N-1) ? "\n" : " ");
		return 0;
	}
	return 0;
}

// look at my code
// my code is amazing