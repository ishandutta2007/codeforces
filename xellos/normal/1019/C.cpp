#include <bits/stdc++.h>
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
#define OVER9000 1234567890123456789LL
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
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N), Gi(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		Gi[v].push_back(u);
	}

	queue<int> q;
	vector<bool> in_q(N, false), removed(N, false);
	vector<bool> has_link(N, false), has_backlink(N, false);
	for(int i = 0; i < N; i++) if(!in_q[i]) {
		q.push(i);
		in_q[i] = true;
		while(!q.empty()) {
			if(has_backlink[q.front()] && has_link[q.front()]) removed[q.front()] = true;
			if(!removed[q.front()]) {
				ALL_THE(Gi[q.front()], it) has_backlink[*it] = true;
				ALL_THE(G[q.front()], it) has_link[*it] = true;
			}
			ALL_THE(G[q.front()], it) if(!in_q[i]) {
				in_q[*it] = true;
				q.push(*it);
			}
			q.pop();
		}
	}

	int cnt = N;
	vector<bool> used(N, true);
	for(int i = 0; i < N; i++) if(removed[i]) used[i] = false, cnt--;
	vector<int> deg(N, 0);
	for(int i = 0; i < N; i++) if(!removed[i])
		ALL_THE(G[i], it) if(!removed[*it]) deg[*it]++;
	for(int i = 0; i < N; i++) if(deg[i] == 0 && !removed[i]) q.push(i);
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(!removed[*it]) {
			if(used[q.front()] && used[*it]) used[*it] = false, cnt--;
			deg[*it]--;
			if(deg[*it] == 0) q.push(*it);
		}
		q.pop();
	}

	cout << cnt << "\n";
	for(int i = 0; i < N; i++) if(used[i]) cout << i+1 << "\n";
	return 0;
}

// look at my code
// my code is amazing