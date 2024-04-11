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

cat mod = 998244353;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<char> > A(N, vector<char>(N, 0));
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		A[u-1][v-1] = 3;
	}
	vector< pair<int, int> > D(N);
	for(int i = 0; i < N; i++) {
		D[i] = {0, i};
		for(int j = 0; j < N; j++) D[i].ff += A[i][j]&1;
	}
	sort(begin(D), end(D));
	for(int i = 0; i < N*(N-1)/2-M; i++) {
		bool found = false;
		for(int j = 0; j < N; j++) for(int k = N-1; k > j; k--) {
			if(found) break;
			if(A[D[j].ss][D[k].ss] + A[D[k].ss][D[j].ss]) continue;
			A[D[j].ss][D[k].ss] = 1;
			D[j].ff++;
			found = true;
		}
		sort(begin(D), end(D));
	}
	while(D.back().ff-D[0].ff > 1) {
		bool stop = true;
		for(int i = N-1; i >= 0; i--) if(D[i].ff > 1+D[0].ff) {
			vector<int> prev(N, -1);
			prev[i] = i;
			static queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int v = q.front();
				q.pop();
				for(int j = 0; j < N; j++) if(A[D[v].ss][D[j].ss] == 1 && prev[j] == -1) {
					prev[j] = v;
					q.push(j);
				}
			}
			for(int j = 0; j < N; j++) if(D[j].ff < D[i].ff-1 && prev[j] != -1) {
				int cur = j;
				while(cur != i) {
					swap(A[D[prev[cur]].ss][D[cur].ss], A[D[cur].ss][D[prev[cur]].ss]);
					D[prev[cur]].ff--;
					D[cur].ff++;
					cur = prev[cur];
					stop = false;
				}
				break;
			}
		}
		sort(begin(D), end(D));
		if(stop) break;
	}
	int ans = N*(N-1)*(N-2)/6;
	for(int i = 0; i < N; i++) ans -= D[i].ff * (D[i].ff-1) / 2;
	cerr << ans << "\n";
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cout << (int)(A[i][j]&1) << ((j == N-1) ? "\n" : "");
	return 0;
}

// look at my code
// my code is amazing