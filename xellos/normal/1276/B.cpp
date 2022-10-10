// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M, A[2];
		cin >> N >> M >> A[0] >> A[1];
		A[0]--, A[1]--;
		vector< vector<int> > G(N);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		vector<int> comp(N, -1);
		comp[A[0]] = -2;
		int c = 0;
		static queue<int> q;
		for(int i = 0; i < N; i++) if(comp[i] == -1) {
			comp[i] = i;
			q.push(i);
			while(!q.empty()) {
				if(q.front() == A[1]) c = i;
				for(auto v : G[q.front()]) if(comp[v] == -1) {
					comp[v] = i;
					q.push(v);
				}
				q.pop();
			}
		}
		vector<char> between(N, 0);
		q.push(A[0]);
		while(!q.empty()) {
			if(q.front() == A[1]) {
				q.pop();
				continue;
			}
			for(auto v : G[q.front()]) if(comp[v] == c && !between[v]) {
				between[v] = 1;
				q.push(v);
			}
			q.pop();
		}
		cat ans[2] = {0, 0};
		for(int i = 0; i < N; i++) if(comp[i] != c && i != A[0]) ans[0]++;
		for(int i = 0; i < N; i++) if(comp[i] == c && !between[i]) ans[1]++;
		cout << ans[0] * ans[1] << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing