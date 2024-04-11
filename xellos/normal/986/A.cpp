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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, K, S;
	cin >> N >> M >> K >> S;
	vector< vector<int> > A(K);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[--a].push_back(i);
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector< vector<int> > dist(K);
	for(int i = 0; i < K; i++) {
		dist[i] = vector<int>(N, OVER9000);
		queue<int> q;
		for(int j = 0; j < (int)A[i].size(); j++) {
			dist[i][A[i][j]] = 0;
			q.push(A[i][j]);
		}
		while(!q.empty()) {
			ALL_THE(G[q.front()], it) if(dist[i][*it] == OVER9000) {
				dist[i][*it] = dist[i][q.front()]+1;
				q.push(*it);
			}
			q.pop();
		}
	}
	for(int i = 0; i < N; i++) {
		vector<int> v;
		for(int j = 0; j < K; j++) v.push_back(dist[j][i]);
		nth_element(begin(v), begin(v)+S-1, end(v));
		cat ans = 0;
		int s = S;
		for(int j = 0; j < K; j++) if(v[j] < v[S-1]) {
			ans += v[j];
			s--;
		}
		for(int j = 0; j < K; j++) if(v[j] == v[S-1] && s > 0) {
			ans += v[j];
			s--;
		}
		cout << ans << "\n";
	}
	return 0;}

// look at my code
// my code is amazing