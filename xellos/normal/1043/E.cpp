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
	int N, M;
	cin >> N >> M;
	vector<int> X(N), Y(N);
	vector< pair<int, int> > order(N);
	for(int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		order[i] = {X[i]-Y[i], i};
	}
	sort(begin(order), end(order));
	vector<cat> sumY(N+1, 0), sumX(N+1, 0);
	for(int i = 0; i < N; i++) sumX[i+1] = sumX[i] + X[order[i].ss];
	for(int i = 0; i < N; i++) sumY[i+1] = sumY[i] + Y[order[N-1-i].ss];
	vector<cat> ans(N, 0);
	int a = 0;
	for(int i = 0; i < N; i++) {
		while(a < N && order[a].ff < order[i].ff) a++;
		int id = order[i].ss;
		ans[id] += 1LL * a * Y[id] + 1LL * (N-1-a) * X[id];
		ans[id] += sumX[a] + sumY[N-a] - Y[id];
	}
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		cat score = min(X[u]+Y[v], X[v]+Y[u]);
		ans[u] -= score;
		ans[v] -= score;
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing