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

int center(vector< vector<int> > & G) {
	int N = G.size();
	vector<int> dep1(N, -1);
	queue<int> q;
	q.push(0);
	dep1[0] = 0;
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dep1[*it] == -1) {
			dep1[*it] = dep1[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	int mxd = 0, mxdv = 0;
	for(int i = 0; i < N; i++) if(dep1[i] >= mxd) {
		mxdv = i;
		mxd = dep1[i];
	}
	vector<int> dep2(N, -1);
	q.push(mxdv);
	dep2[mxdv] = 0;
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dep2[*it] == -1) {
			dep2[*it] = dep2[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	int mxd2 = 0, mxdv2 = 0;
	for(int i = 0; i < N; i++) if(dep2[i] >= mxd2) {
		mxdv2 = i;
		mxd2 = dep2[i];
	}
	vector<int> dep3(N, -1);
	q.push(mxdv2);
	dep3[mxdv2] = 0;
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dep3[*it] == -1) {
			dep3[*it] = dep3[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	for(int i = 0; i < N; i++) if(dep2[i] + dep3[i] == mxd2 && dep2[i] == dep3[i]) return i;
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	int R = center(G);
	if(R == -1) {
		cout << "No\n";
		return 0;
	}
	vector<int> dep(N, -1);
	queue<int> q;
	q.push(R);
	dep[R] = 0;
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dep[*it] == -1) {
			dep[*it] = dep[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	int mxdep = 0;
	for(int i = 0; i < N; i++) mxdep = max(mxdep, dep[i]);
	if(mxdep != K) {
		cout << "No\n";
		return 0;
	}
	for(int i = 0; i < N; i++) if(dep[i] < K) {
		int sons = 0;
		ALL_THE(G[i], it) if(dep[*it] > dep[i]) sons++;
		if(sons < 3) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}

// look at my code
// my code is amazing